package cardgames.italian;

import java.util.NoSuchElementException;

public class OneTwoThreeSoliaire {

    private ItalianDeck deck;

    private int currentCount = 0;

    private boolean win = false;
    private boolean endGame = false;

    public OneTwoThreeSoliaire() {
        initilizeGame();
    }

    public void initilizeGame() {
        win = false;
        endGame = false;
        currentCount = 0;
        deck = new ItalianDeck();
    }

    public void play() {
        if (endGame) {
            if (win) {
                System.out.println("You win! initialize game to restart");
            } else {
                System.out.println("You lose! initialize game to restart");
            }
            return;
        }
        currentCount = currentCount % 3;
        currentCount += 1;
        try {
            ItalianCard card = deck.pull();
            if (card.getValue().getNumericValue() == currentCount) {
                endGame = true;
                win = false;
            }
        } catch (NoSuchElementException e) {
            endGame = true;
            win = true;
        }
    }

    public boolean isFinished() {
        return endGame;
    }

    public boolean won() {
        return win;
    }

    public void restart() {
        initilizeGame();
    }

    public static void main(String[] args) {
        OneTwoThreeSoliaire solitaire = new OneTwoThreeSoliaire();
        int subsequentlyLoss = 0;
        while (!solitaire.won()) {
            solitaire.play();
            if (solitaire.isFinished() && !solitaire.won()) {
                solitaire.restart();
                subsequentlyLoss += 1;
            }
        }
        System.out.println(String.format("Won after %s games",subsequentlyLoss));
    }
}
