package labyrinth;

import java.util.Random;
import java.util.Stack;

public class Map
{
    private int[][] map ;

    private int n = 20;

    private int x = 0,y = 0;

    private int leftX,rightX,downY,upY;

    private Stack<Integer> stackX = new Stack<>();

    private Stack<Integer> stackY = new Stack<>();

    public Map()
    {
        this(20,0,0);
    }

    public Map(int n)
    {
        this(n,0,0);
    }

    public Map(int n,int x,int y)
    {
        this.n = n;
        this.x = x;
        this.y = y;
        this.map = new int[n][n];
    }

    public void createMap()
    {
        stackX.push(x);
        stackY.push(y);
        map[y][x] = 1;
        while(!stackX.empty())
        {
            while(haveNextStep())
            {
                nextLocation();
                stackX.push(x);
                stackY.push(y);
                map[y][x] = 1;
                for(int i = 0;i < n;i++)
                {
                    for (int j = 0; j < n; j++)
                        System.out.printf("%3d", map[i][j]);
                    System.out.println();
                }
                System.out.println("下一张");
            }
            stackX.pop();
            stackY.pop();
            if(!stackX.empty())
            {
                setX(stackX.peek());
                setY(stackY.peek());
            }
        }
    }

    public void nextLocation()
    {
        setRoundLocation(x,y);
        while(map[y][x]==1)
        {
            switch (new Random().nextInt(4))
            {
                case 0:
                    if(map[upY][x] == 1)
                        break;
                    else
                    {
                        setY(upY);
                        break;
                    }
                case 1:
                    if(map[downY][x] == 1)
                        break;
                    else
                    {
                        setY(downY);
                        break;
                    }
                case 2:
                    if(map[y][leftX] == 1)
                        break;
                    else
                    {
                        setX(leftX);
                        break;
                    }
                case 3:
                    if(map[y][rightX] == 1)
                        break;
                    else
                    {
                        setX(rightX);
                        break;
                    }
            }
        }
    }

    public boolean haveNextStep()
    //该位置四周是不是还有没访问过的
    {
        setRoundLocation(x,y);
        return (map[downY][x]==0||map[y][leftX]==0||map[y][rightX]==0||map[upY][x]==0);
    }

    public void setRoundLocation(int x,int y)
    {
        leftX = this.x == 0 ? this.x : this.x - 1;
        rightX = this.x == this.n - 1 ? this.x : this.x + 1;
        upY = this.y == 0 ? y : y - 1;
        downY = this.y == this.n - 1 ? this.y : this.y + 1;
    }

    public int[][] getMap()
    {
        return map;
    }

    public Stack<Integer> getStackX()
    {
        return stackX;
    }

    public void setStackX(Stack<Integer> stackX)
    {
        this.stackX = stackX;
    }

    public Stack<Integer> getStackY()
    {
        return stackY;
    }

    public void setStackY(Stack<Integer> stackY)
    {
        this.stackY = stackY;
    }

    public int getN()
    {
        return n;
    }

    public void setN(int n)
    {
        this.n = n;
    }

    public int getX()
    {
        return x;
    }

    public void setX(int x)
    {
        this.x = x;
    }

    public int getY()
    {
        return y;
    }

    public void setY(int y)
    {
        this.y = y;
    }
}
