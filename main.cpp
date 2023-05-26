#include <iostream>
#include <algorithm>
#include <random>

int round(int human_choice, std::string* options) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2);

    int bot_choice = dist(rng);

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
    std::string human_choice;
    std::string options[3] = {"Rock", "Paper", "Scissors"};
    int human_score = 0, bot_score = 0;

    std::cout << "Let's play Rock Paper Scissors! We'll have 10 rounds." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i + 1 << ".Your pick: ";
        std::cin >> human_choice;

        std::string* it = std::find(options, options + 3, human_choice);

        if (it != options + 3) {
            int result = round(int(it - options), options);

            switch (result)
            {
                case -1: std::cout << human_score << " : " << ++bot_score << std::endl; break;
                case 0: std::cout << human_score << " : " << bot_score << std::endl; break;
                case 1:std::cout << ++human_score << " : " << bot_score << std::endl; break;
                default: std::cout << "error"; break;
            }
        }
        else
        {
            std::cout << "This is not a valid pick, please try again\n";
            --i;
            continue;
        }
    }

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

    return 0;
}
