package ex003.chess.logic;

public enum ChessType
{
    WK("W"),WQ("W"),WR("W"),WB("W"),WN("W"),WP("W"),BK("B"),BQ("B"),BR("B"),BB("B"),BN("B"),BP("B");

    private String side;

    ChessType(String side)
    {
        this.side = side;
    }

    public String getSide()
    {
        return side;
    }
}
