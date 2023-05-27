#include <iostream>
#include <algorithm>
#include <random>

int round(int human_choice, int bot_choice, std::string* options) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2);

    if (bot_choice == -1 || dist(rng) != 0)
    {
        bot_choice = dist(rng);
    }

    std::cout << options[human_choice] << " vs " << options[bot_choice] << std::endl;

    if (human_choice == bot_choice) {
        return 0;
    }

    if (abs(human_choice - bot_choice) == 2)
    {
        return human_choice > bot_choice ? -1 : 1;
    }

    return human_choice > bot_choice ? 1 : -1;
}


int main() {
    std::string reply;
    std::string accepted_replies[9] = {"rock", "r", "1", "paper", "p", "2", "scissors", "s", "3"};
    std::string options[3] = {"Rock", "Paper", "Scissors"};
    int human_score = 0, bot_score = 0;
    int n_of_rounds;
    int human_choice, bot_choice = -1;

    std::cout << "Let's play Rock Paper Scissors!\n";
    std::cout << "Please enter how many rounds you want to have: ";
    std::cin >> n_of_rounds;

    for (int i = 0; i < n_of_rounds; ++i)
    {
        std::cout << i + 1 << ".Your pick: ";
        std::cin >> reply;

        std::string* it = std::find(accepted_replies, accepted_replies + 9, reply);

        if (it != accepted_replies + 9) {
            human_choice = int(it - accepted_replies) / 3;
            int result = round(human_choice, bot_choice, options);

            switch (result)
            {
                case -1: std::cout << human_score << " : " << ++bot_score << std::endl; bot_choice = (human_choice + 2) % 3; break;
                case 0: std::cout << human_score << " : " << bot_score << std::endl; bot_choice = -1; break;
                case 1:std::cout << ++human_score << " : " << bot_score << std::endl; bot_choice = (human_choice + 1) % 3; break;
            }
        }
        else
        {
            std::cout << "This is not a valid pick, please try again\n";
            --i;
            continue;
        }
    }

    if (n_of_rounds > 0)
    {
        std::cout << "\nFinal score: " << human_score << " : " << bot_score << std::endl;

        if (human_score < bot_score)
        {
            std::cout << "You lost. Better luck next time!\n";
        }
        else if (human_score == bot_score)
        {
            std::cout << "It's a draw. You are a worthy opponent!\n";
        }
        else
        {
            std::cout << "You won! Well done!\n";
        }
    }
    else
    {
        std::cout << "Why did you run the game if you didn't want to play it?\n";
    }

    return 0;
}
