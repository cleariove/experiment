package ex001.calculate;

import javafx.scene.control.Alert;
import javafx.scene.control.TextInputDialog;



public class Addition
{
    private TextInputDialog dialog = new TextInputDialog("输入表达式");
    private Alert alert = new Alert(Alert.AlertType.INFORMATION);
    public Addition()
    {

    }


    public void paint()
    {
        dialog.setTitle("计算");
    }

    public void showResult(double num)
    {
        alert.setHeaderText("结果为"+num);
        alert.showAndWait();
    }

    public TextInputDialog getDialog()
    {
        return dialog;
    }

    public void setDialog(TextInputDialog dialog)
    {
        this.dialog = dialog;
    }


}
