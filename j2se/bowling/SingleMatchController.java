package bowling;


import bowling.logic.AllPlayers;
import bowling.logic.Record;
import bowling.logic.SingleMatch;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;

import java.net.URL;
import java.util.ResourceBundle;

public class SingleMatchController  implements Initializable {
    @FXML
    TableColumn Name;
    @FXML
    TableView<Record> table;
    @FXML
    private TableColumn ID;
    @FXML
    private TableColumn one;
    @FXML
    private TableColumn one_1;


    public void text() {

        ObservableList<Record> list = FXCollections.observableArrayList();

        AllPlayers allPlayers = new bowling.logic.AllPlayers();
        try
        {
            allPlayers.initialize();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        bowling.logic.RoundRecords[][] singleRecords = new bowling.logic.RoundRecords[6][10];
        SingleMatch singleMatch = new SingleMatch(allPlayers,singleRecords);
        singleMatch.matchBegin();

        singleMatch.setPlayerRecord();
        allPlayers.sortPlayerBySingleScore();
        allPlayers.forEach(e->System.out.println(e));
        for(int i =0;i< 60;i++) {
            allPlayers.get(i).getSingleRecord().forEach(e->System.out.println(e));
            list.addAll(allPlayers.get(i).getSingleRecord());
        }

        Name.setCellValueFactory(new PropertyValueFactory("name"));
        ID.setCellValueFactory(new PropertyValueFactory("teamNum"));
        one_1.setCellValueFactory(new PropertyValueFactory<>("firstScore"));

        //list.add(record);        //list添加值对象
        table.setItems(list);


//        AllPlayer allPlayer = new AllPlayer();
//        AllRecord singleRecord = new AllRecord();
//        SingleMatch singleMatch = new SingleMatch(allPlayer,singleRecord);
//        singleMatch.matchBegin();
//
//        singleMatch.matchResult();
//        System.out.println(singleRecord.getRecords().toString());
        //Name.setText("CSS");
        //  table;

    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        text();
    }

}
