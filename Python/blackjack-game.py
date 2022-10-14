#This is a simple text-based blackjack game. Its very easy and fun to play. The game includes two options Hit and stand
#You play against an automated dealer and the game asks if you want to continue after each round.
#The code takes accont of all your busts, wins, losses, draws and balance too. You can play until your balance falls below minimum bet or you quit.
#You can change min_bet, max_bet, initial Balance. I have specified the position for such changes in code.
import random 
suits=('♥','♦','♠','♣')
ranks=('Two','Three','Four','Five','Six','Seven','Eight','Nine','Ten','Jack','Queen','King','Ace')
values={'Two':2,'Three':3,'Four':4,'Five':5,'Six':6,'Seven':7,'Eight':8,'Nine':9,'Ten':10,'Jack':10,'Queen':10,'King':10,'Ace':11}
class Card:
    
    def __init__(self,suit,rank):
        self.suit=suit
        self.rank=rank
        self.value=values[rank]
    def __str__(self):
        return self.rank + ' of '+self.suit

class Deck():
    def __init__(self):
        self.all_cards=[]
        for suit in suits:
            for rank in ranks:
                self.all_cards.append(Card(suit,rank))
    
    def shuffle(self):
        random.shuffle(self.all_cards)
    def deal_one(self):
        return self.all_cards.pop()

class Player():
    def __init__(self,name,balance):
        self.name=name
        self.balance=balance
        self.wins=0
        self.losses=0
        self.busts=0
        self.draws=0
        self.all_cards=[]
        self.aces=0
    def add_balance(self,amount):
        self.balance=self.balance+amount
    def add_wins(self):
        self.wins+=1
    def add_losses(self):
        self.losses+=1
    def add_busts(self):
        self.busts+=1
    def add_draws(self):
        self.draws+=1
    def withdraw(self,amount):
        if amount>self.balance:
            print('Out of Cash!')
        else:
            self.balance=self.balance-amount
    def board(self):
        print('Name: {}'.format(self.name))
        print('Balance: ${}'.format(self.balance))
        print(f'Wins: {self.wins}  Losses: {self.losses}  Busts: {self.busts}  Draws: {self.draws}')

def hit_stand():
    choices=['H','S']
    choice='wrng'
    while choice not in choices:
        choice=input('H(h):Hit  S(s):Stand').upper()
        if choice not in choices:
            print('Sorry, invalid input')
        else:
            return choice

def display(m,M,p_board,p_card,d_card):
    print('Min Bet:${}  Max Bet:${}'.format(m,M))
    p_board.board()
    print('Player Cards: ')
    for x in p_card:
        print(f'     {x}')
    if type(d_card)==type([]):
        print('Dealer Cards: ')
        for y in d_card:
            print(f'     {y}')
    else:
        print(f'Dealer Cards: {d_card}')

def game_on():
    choices=['Y','N']
    choice='wrong'
    while choice not in choices:
        choice=input('Do you want to continue the game?(Y or N)').upper()
        if choice not in choices:
            print('Sorry, invalid input')
        elif choice=='Y':
            return True
        elif choice=='N':
            return False

def user_input(a,min_bet,max_bet):
    while True:
        x=input(a)
        if x.isdigit==False or int(x)>max_bet or int(x)<min_bet:
            print('Inavalid input')
            continue
        else:
            break
    return int(x)

def value_sum(player):
    v_sum=0
    aces=0
    for card in player:
        v_sum+=card.value
        if card.rank=='Ace':
            aces+=1
    while v_sum>21 and aces>0:
        v_sum-=10
        aces-=1
    return v_sum

from IPython.display import clear_output
def blackjack():
    my_deck=Deck()
    my_deck.shuffle()
    min_bet=50                                                          #min_bet can be changed here
    max_bet=500                                                         #max_bet can be changed here
    name=input('Enter your name here: ')
    print('You will be given an initial balance of $200!')
    player1=Player(name,200)                                            #200 represents initial balance you can change it if you want.
    clear_output()
    while game_on()==True:
        clear_output()
        if player1.balance<min_bet:
            print('Out of Money!')
            break
        print(f'Min Bet: {min_bet} Max Bet: {max_bet}')
        bet=user_input('Place your Bet: ',min_bet,player1.balance)
        player1_cards=[]
        dealer_cards=[]
        for x in range(2):
            player1_cards.append(my_deck.deal_one())
            dealer_cards.append(my_deck.deal_one())
        display(min_bet,max_bet,player1,player1_cards,dealer_cards[0])
        if value_sum(player1_cards)==21:
                print('!!!Blackjack!!!')
                player1.add_balance(1.5*bet)
                player1.add_wins()
                display(min_bet,max_bet,player1,player1_cards,dealer_cards[0])
                continue
        while hit_stand()=='H':
            clear_output()
            player1_cards.append(my_deck.deal_one())
            display(min_bet,max_bet,player1,player1_cards,dealer_cards[0])
            if value_sum(player1_cards)>21:
                print('!!!sum exceeded 21, you got Busted!!!')
                player1.withdraw(bet)
                player1.add_busts()
                break
            else:
                continue
        if value_sum(player1_cards)>21:
            display(min_bet,max_bet,player1,player1_cards,dealer_cards[0])
            continue
        while value_sum(dealer_cards)<17:
            dealer_cards.append(my_deck.deal_one())
        if value_sum(dealer_cards)>21:
            print('!!!Dealer got busted. A win, Nice!!!')
            player1.add_balance(bet)
            player1.add_wins()
            display(min_bet,max_bet,player1,player1_cards,dealer_cards)
            continue
        if value_sum(player1_cards)>value_sum(dealer_cards):
            print('!!!A win, Nice!!!')
            player1.add_balance(bet)
            player1.add_wins()
        if value_sum(player1_cards)<value_sum(dealer_cards):
            print('!!!Sorry, a loss!!!')
            player1.withdraw(bet)
            player1.add_losses()
        if value_sum(player1_cards)==value_sum(dealer_cards):
            print('!!!Draw!!!')
            player1.add_draws()
        display(min_bet,max_bet,player1,player1_cards,dealer_cards)
blackjack()
