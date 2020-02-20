package ex001.calculate;

import javafx.application.Application;

import javafx.stage.Stage;

public class TestAddition extends Application{
    @Override
    public void start(Stage primaryStage) throws Exception {
        Addition addition = new Addition();
        SplitString splitString = new SplitString();
        Calculate calculate = new Calculate();
        addition.paint();
        addition.getDialog().showAndWait();
        String s = addition.getDialog().getResult();
        splitString.setS(s);
        splitString.split();
        addition.showResult(calculate.getResult(splitString.getNum1(),splitString.getNum2(),splitString.getOperator()));
    }

    public static void main(String... args){
        Application.launch(args);
    }
}
