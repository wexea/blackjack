#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int getRandomCard()
{
    return rand() % 10 + 1;
}
int getHandValue(int hand[], int numCards)
{
    int value = 0;
    int numAces = 0;
    for (int i = 0; i < numCards; i++)
    {
        value += hand[i];

        if (hand[i] == 1)
            numAces++;
    }
    while (value <= 11 && numAces > 0)
    {
        value += 10;
        numAces--;
    }
    return value;
}
int main()
{
    srand(time(0)); 
    int playerHand[9]; 
    int dealerHand[9];
    int numPlayerCards = 0;
    int numDealerCards = 0;
    playerHand[numPlayerCards++] = getRandomCard();
    dealerHand[numDealerCards++] = getRandomCard();
    playerHand[numPlayerCards++] = getRandomCard();
    dealerHand[numDealerCards++] = getRandomCard();
    char choice;
    while (true)
    {
        cout << "[@] Your cards: ";
        for (int i = 0; i < numPlayerCards; i++)
        {
            cout << playerHand[i] << " ";
        }
        cout << "\n[#] Total value of your cards: " << getHandValue(playerHand, numPlayerCards) << endl;
        cout << "[#] Do you want to draw another card? [y/n] : ";
        cin >> choice;
        if (choice == 'y')
        {
            playerHand[numPlayerCards++] = getRandomCard();

            if (getHandValue(playerHand, numPlayerCards) > 21)
            {
                cout << "[!] Bust! You lose." << endl;
                return 0;
            }
        }
        else
        {
            break;
        }
    }
    while (getHandValue(dealerHand, numDealerCards) < 17)
    {
        dealerHand[numDealerCards++] = getRandomCard();
    }
    cout << "\n[@] Dealer's cards: ";
    for (int i = 0; i < numDealerCards; i++)
    {
        cout << dealerHand[i] << " ";
    }
    cout << "\n[#] Total value of dealer's cards: " << getHandValue(dealerHand, numDealerCards) << endl;
    int playerValue = getHandValue(playerHand, numPlayerCards);
    int dealerValue = getHandValue(dealerHand, numDealerCards);
    if (playerValue > dealerValue || dealerValue > 21)
    {
        cout << "[!] You win!" << endl;
    }
    else if (playerValue < dealerValue)
    {
        cout << "[!] You lose." << endl;
    }
    else
    {
        cout << "[!] It's a tie." << endl;
    }
    return 0;
}

// DEXP
// EFNCD werwerwerewr sd
