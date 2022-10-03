package cardgames.italian;

import java.util.Arrays;

public class ItalianCard {

    public enum Type {GOLD, SWORDS, CUPS, CLUBS;
        public String unicodeSymbol() {
            switch (this){
                case CUPS:
                    return "\uD83C\uDFC6";
                case GOLD:
                    return "☀️";
                case CLUBS:
                    return "\uD83E\uDEB5";
                default:
                    return "⚔️";
            }
        }
    }

    public enum Value {
        ACE(1), TWO(2), THREE(3), FOUR(4), FIVE(5), SIX(6), SEVEN(7), KNAVE(8), KNIGHT(9), KING(10);

        int numericValue;

        Value(int value) {
            this.numericValue = value;
        }

        public static Value getByNumericValue(int value) {
            return Arrays.stream(Value.values()).filter(c -> c.numericValue==value).findFirst().orElse(Value.ACE);
        }

        public String unicodePrefix() {
            switch (this){
                case KNAVE:
                    return "J";
                case KNIGHT:
                    return "Q";
                case KING:
                    return "K";
                default:
                    return this.numericValue+"";
            }
        }

        public int getNumericValue() { return numericValue; }
    }

    private Type type;
    private Value value;

    public ItalianCard(Type type, Value value) {
        this.type = type;
        this.value = value;
    }

    public Type getType() { return type; }

    public void setType(Type type) { this.type = type; }

    public Value getValue() { return value; }

    public void setValue(Value value) { this.value = value; }

    @Override
    public String toString() {
        return String.format("(%s%s)",
                type.unicodeSymbol(),value.unicodePrefix());
    }
}
