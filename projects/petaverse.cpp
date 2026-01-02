#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#ifdef _WIN32
#include <windows.h>
#endif
#ifdef _WIN32
void enableUTF8()
{
    SetConsoleOutputCP(CP_UTF8);
}
#endif

string toLower(const string &str)
{
    string res = str;
    transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}

//  pet game
struct Food
{
    string name;
    int cost;
    int energyBoost;
    int happinessEffect;
};

struct Toy
{
    string name;
    int energyCost;
    int happinessBoost;
};

class Pet
{
public:
    string species;
    string breed;
    string nickname;
    int energy = 30;
    int happiness = 0;

    vector<Food> foods;
    vector<Toy> toys;

    Pet(string species, string breed, string nickname)
        : species(species), breed(breed), nickname(nickname) {}

    string getPetIcon() const
    {
        if (toLower(species) == "dog")
            return "🐕";
        else if (toLower(species) == "cat")
            return "🐈";
        else if (toLower(species) == "rabbit")
            return "🐇";
        return "🐾"; 
    }

    void feed(int &cash)
    {
        cout << "\nChoose food to feed " << getPetIcon() << " " << nickname << ":\n";
        for (size_t i = 0; i < foods.size(); ++i)
        {
            cout << i + 1 << ". " << foods[i].name << " ($" << foods[i].cost
                 << ", +" << foods[i].energyBoost << "% energy, "
                 << ((foods[i].happinessEffect >= 0) ? "+" : "")
                 << foods[i].happinessEffect << "% happiness)\n";
        }

        int choice;
        cin >> choice;
        if (choice < 1 || choice > (int)foods.size())
        {
            cout << "Invalid food choice.\n";
            return;
        }

        Food selected = foods[choice - 1];

        if (cash < selected.cost)
        {
            cout << "❌ Not enough cash!\n";
            return;
        }

        cash -= selected.cost;
        energy += selected.energyBoost;
        happiness += selected.happinessEffect;

        cout << getPetIcon() << " " << nickname << " ate " << selected.name << "!\n";
        if (energy > 100)
            energy = 100;
        if (happiness > 100)
            happiness = 100;
    }

    void play()
    {
        cout << "\nAvailable toys to play with " << getPetIcon() << " " << nickname << ":\n";
        for (size_t i = 0; i < toys.size(); ++i)
        {
            cout << i + 1 << ". " << toys[i].name << " (-" << toys[i].energyCost
                 << "% energy, +" << toys[i].happinessBoost << "% happiness)\n";
        }

        int choice;
        cout << "Choose a toy (1-" << toys.size() << "): ";
        cin >> choice;
        if (choice < 1 || choice > (int)toys.size())
        {
            cout << "Invalid toy choice.\n";
            return;
        }

        Toy selected = toys[choice - 1];

        if (energy < selected.energyCost)
        {
            cout << "❌ " << nickname << " is too tired to play right now!\n";
            return;
        }

        energy -= selected.energyCost;
        happiness += selected.happinessBoost;

        cout << getPetIcon() << " " << nickname << " played with " << selected.name << "!\n";
        if (energy < 0)
            energy = 0;
        if (happiness > 100)
            happiness = 100;
    }

    void sleep()
    {
        cout << getPetIcon() << " " << nickname << " is sleeping... 😴\n";
        Sleep(1000); // Sleep animation
        energy += 20;
        happiness += 10;
        if (energy > 100)
            energy = 100;
        if (happiness > 100)
            happiness = 100;
    }

    void showStatus(int cash)
    {
        cout << "\n--- " << getPetIcon() << " " << nickname << "'s Status ---\n";
        cout << "Species: " << species << " | Breed: " << breed << "\n";
        cout << "Energy: [";
        for (int i = 0; i < 10; i++)
        {
            if (i < energy / 10)
                cout << "■";
            else
                cout << "□";
        }
        cout << "] " << energy << "%\n";

        cout << "Happiness: [";
        for (int i = 0; i < 10; i++)
        {
            if (i < happiness / 10)
                cout << "■";
            else
                cout << "□";
        }
        cout << "] " << happiness << "%\n";
        
        cout << "Your Cash: $" << cash << "\n";

        if (energy <= 10)
            cout << "⚠️ Warning: Energy is critically low!\n";
        if (happiness <= 10)
            cout << "⚠️ Warning: Happiness is critically low!\n";
    }

    bool checkWinLose()
    {
        if (energy <= 0 || happiness <= 0)
        {
            cout << "\n💀 " << getPetIcon() << " " << nickname << " has lost the game...\n";
            return true;
        }
        if (energy >= 100 && happiness >= 100)
        {
            cout << "\n🎉 " << getPetIcon() << " " << nickname << " is perfectly happy and energetic! You win!\n";
            return true;
        }
        return false;
    }
};

class Game
{
private:
    int feedCount = 0, playCount = 0, sleepCount = 0;
    const int MAX_FEEDS = 5;
    const int MAX_PLAYS = 4;
    const int MAX_SLEEPS = 3;

    Pet *pet;
    int cash = 200;

    vector<string> dogBreeds = {"Labrador", "Poodle", "Bulldog"};
    vector<string> catBreeds = {"Siamese", "Persian", "MaineCoon"};
    vector<string> rabbitBreeds = {"Dutch", "Angora", "Lop"};

public:
    void printRules()
    {
        cout << "📜 -------- Welcome to Petaverse Rules -------- 📜\n";
        cout << "1. You start with $200 to take care of your pet.\n";
        cout << "2. Choose a pet (Dog 🐕, Cat 🐈, or Rabbit 🐇) and give it a name.\n";
        cout << "3. Your pet starts with 30% energy and 0% happiness.\n";
        cout << "4. Actions you can take:\n";
        cout << "   🥣 Feed - Costs money, increases energy or happiness based on food type.\n";
        cout << "   🎾 Play - Uses energy, increases happiness using toys.\n";
        cout << "   😴 Sleep - Restores both energy and happiness.\n";
        cout << "5. If energy or happiness reaches 0%, you lose the game. ⚠️\n";
        cout << "6. If both energy and happiness reach 100%, you win! 🏆\n";
        cout << "7. Be smart with your money! If you run out, you can't buy food. 💸\n";
        cout << "8. You'll be warned when levels drop below 10%.\n";
        cout << "🧠 Strategic Limitations:\n";
        cout << "   - Max 5 feeds 🥣\n";
        cout << "   - Max 4 plays 🎾\n";
        cout << "   - Max 3 sleeps 😴\n";
        cout << "   Use your actions wisely to win the game!\n";
        cout << "Have fun taking care of your virtual buddy! 🐾\n";
        cout << "--------------------------------------------------\n\n";
    }

    void start()
    {
        printRules();
        cout << "🐾 Welcome to Petaverse 🐾\n";
        string type;
        cout << "Choose your pet (Dog 🐕, Cat 🐈, Rabbit 🐇): ";
        cin >> type;
        type = toLower(type);

        vector<string> breedList;
        if (type == "dog")
            breedList = dogBreeds;
        else if (type == "cat")
            breedList = catBreeds;
        else if (type == "rabbit")
            breedList = rabbitBreeds;
        else
        {
            cout << "Invalid pet type.\n";
            return;
        }

        cout << "Available breeds:\n";
        for (const string &b : breedList)
            cout << "- " << b << "\n";

        string breed, nickname;
        cout << "Choose a breed: ";
        cin >> breed;
        cout << "Give your pet a nickname: ";
        cin >> nickname;

        pet = new Pet(type, breed, nickname);
        loadPetData(type);

        run();
    }

    void loadPetData(const string &type)
    {
        if (type == "dog")
        {
            pet->foods = {
                {"Kibble", 50, 30, -10},
                {"Bone", 30, 0, 20},
                {"Premium Dog Food", 70, 40, 10}};
            pet->toys = {
                {"Ball", 15, 25},
                {"Frisbee", 20, 30}};
        }
        else if (type == "cat")
        {
            pet->foods = {
                {"Tuna", 40, 25, -5},
                {"Milk", 20, 0, 15},
                {"Cat Treats", 60, 30, 20}};
            pet->toys = {
                {"Yarn Ball", 10, 20},
                {"Laser Pointer", 5, 25}};
        }
        else if (type == "rabbit")
        {
            pet->foods = {
                {"Carrot", 30, 20, -5},
                {"Berry", 25, 0, 15},
                {"Lettuce", 20, 15, 10}};
            pet->toys = {
                {"Tunnel Tube", 10, 15},
                {"Chew Toy", 5, 20}};
        }
    }

    void run()
    {
        while (true)
        {
            pet->showStatus(cash);
            cout << "\nChoose an action:\n1. Feed (" << (MAX_FEEDS - feedCount) << " left)"
                 << "\n2. Play (" << (MAX_PLAYS - playCount) << " left)"
                 << "\n3. Sleep (" << (MAX_SLEEPS - sleepCount) << " left)"
                 << "\nYour choice: ";
            int action;
            cin >> action;

            switch (action)
            {
            case 1:
                if (feedCount >= MAX_FEEDS)
                {
                    cout << "❌ No feeding actions left!\n";
                }
                else
                {
                    pet->feed(cash);
                    feedCount++;
                }
                break;
            case 2:
                if (playCount >= MAX_PLAYS)
                {
                    cout << "❌ No play actions left!\n";
                }
                else
                {
                    pet->play();
                    playCount++;
                }
                break;
            case 3:
                if (sleepCount >= MAX_SLEEPS)
                {
                    cout << "❌ No sleep actions left!\n";
                }
                else
                {
                    pet->sleep();
                    sleepCount++;
                }
                break;
            default:
                cout << "Invalid action.\n";
            }

            if (pet->checkWinLose())
                break;

            if (feedCount >= MAX_FEEDS && playCount >= MAX_PLAYS && sleepCount >= MAX_SLEEPS)
            {
                cout << "\n🚫 All actions used up!\n";
                if (pet->energy >= 100 && pet->happiness >= 100)
                {
                    cout << "🏆 You used your moves wisely and WON the game!\n";
                }
                else
                {
                    cout << "💔 You ran out of actions and couldn't win. Game over.\n";
                }
                break;
            }
        }

        delete pet;
    }
};
int main()
{
    enableUTF8();
    Game g;
    g.start();
    return 0;
}
