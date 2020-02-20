package labyrinth;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;

public class MapView extends BorderPane
{
    private Map map;
    private GraphicsContext gc;
    private Canvas canvas;
    private int x,y;
    private double cellLen = 40;
    public MapView()
    {
        map = new Map();
        canvas = new Canvas(cellLen * map.getN(),cellLen * map.getN());
        gc = canvas.getGraphicsContext2D();
    }

    public void builderMap()
    {
        gc.setLineWidth(10);
        gc.setFill(Color.BLACK);
        gc.setStroke(Color.BLACK);
        for(int i = 0;i < map.getN() + 1;i++)
        {
            gc.strokeLine(i * cellLen,0,i * cellLen,cellLen * map.getN());
            gc.strokeLine(0,i * cellLen,cellLen * map.getN(),i * cellLen);
        }
        int i,j;
        map.getStackX().push(map.getX());
        map.getStackY().push(map.getY());
        map.getMap()[map.getY()][map.getX()] = 1;
        gc.fillOval(map.getX() * cellLen + cellLen / 2 -10,map.getY() * cellLen + cellLen / 2 - 10,cellLen / 2,cellLen / 2);
        gc.setStroke(Color.WHITE);
        while(!(map.getStackX()).empty())
        {
            while (map.haveNextStep())
            {
                x = map.getX();
                y = map.getY();
                map.nextLocation();
                (map.getStackX()).push(map.getX());
                (map.getStackY()).push(map.getY());
                map.getMap()[map.getY()][map.getX()] = 1;
                i = map.getX() - x;
                j = map.getY() - y;
                if (i > 0)
                    gc.strokeLine((x + i) * cellLen, y * cellLen + 10, (x + i) * cellLen, (y + 1) * cellLen - 10);
                else if(i < 0)
                    gc.strokeLine(x * cellLen, y * cellLen + 10, x * cellLen, (y + 1) * cellLen - 10);
                if (j > 0)
                    gc.strokeLine(x  * cellLen + 10, (y + j) * cellLen, (x + 1) * cellLen - 10, (y + j) * cellLen);
                else if(j < 0)
                    gc.strokeLine(x  * cellLen + 10, y * cellLen, (x + 1) * cellLen - 10, y * cellLen);
            }

            map.getStackX().pop();
            map.getStackY().pop();
            if (!(map.getStackX()).empty())
            {
                map.setX((map.getStackX()).peek());
                map.setY((map.getStackY()).peek());

            }
        }
        gc.setFill(Color.BLACK);
        gc.fillOval(x * cellLen + cellLen / 2 - 10,y * cellLen + cellLen / 2 - 10,cellLen/2,cellLen/2);
        this.setCenter(canvas);
    }
}
