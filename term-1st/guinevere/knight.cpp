#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue)
{
    cout << "HP=" << HP
         << ", level=" << level
         << ", remedy=" << remedy
         << ", maidenkiss=" << maidenkiss
         << ", phoenixdown=" << phoenixdown
         << ", rescue=" << rescue << endl;
}

int calculateFibo(int n)
{
    if ((n == 1) || (n == 2))
    {
        return 1;
    }

    return (calculateFibo(n - 1) + calculateFibo(n - 2));
}

int calculateLevelO(int i)
{
    int eventIndex = i + 1;
    int b = eventIndex % 10;
    int levelO = (eventIndex > 6) ? ((b > 5) ? b : 5) : b;
    return levelO;
}

void readFileMushGhost(string file_mush_ghost, int arr_mush_ghost[100], int &arr_mush_ghost_length)
{
    fstream fin;

    fin.open(file_mush_ghost, ios::in);

    if (fin.is_open())
    {
        int counter = 1;
        int counter_helper = 0;
        int number;
        string s;

        while (getline(fin, s))
        {
            stringstream s_stream(s);

            switch (counter)
            {
            case 1:
                s_stream >> arr_mush_ghost_length;
                break;

            case 2:
                while (s_stream >> number)
                {
                    arr_mush_ghost[counter_helper] = number;
                    counter_helper += 1;
                }
                break;

            default:
                break;
            }
            counter += 1;
        }
    }

    fin.close();
}

void readFileMerlinPack(string file_merlin_pack, int &HP)
{
    // Call this function when meet merlin for the first time
    fstream fin;

    fin.open(file_merlin_pack, ios::in);

    if (fin.is_open())
    {
        string temp;

        while (getline(fin, temp))
        {
            // temp is now == current words
            // you can just ignore the first integer
            // your logic to increase HP go here
        }
    }
}

void readFileAlcepiusPack(string file_alcepius_pack, int &remedy, int &maidenkiss, int &phoenixdown)
{
    // Call this function when meet alcepius for the first time
    fstream fin;

    fin.open(file_alcepius_pack, ios::in);

    if (fin.is_open())
    {
        int counter = 1;
        int counter_line = 0;
        int number;
        string s;

        while (getline(fin, s))
        {
            stringstream s_stream(s);
            counter_line = 1;

            // ignore the first 2 lines
            if ((counter == 1) || (counter == 2))
            {
                counter += 1;
                continue;
            }

            while (s_stream >> number)
            {
                if ((number == 16) && (counter_line <= 3))
                {
                    remedy += 1;
                    counter_line += 1;
                }

                // Same for the rest
            }
        }
    }

    fin.close();
}

void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
    // Event-Related varibles
    int arr_events[100];
    int arr_events_length = 0;
    string arr_events_helper[3];

    // Read file_input
    fstream fin;

    fin.open(file_input, ios::in);
    if (fin.is_open())
    {
        int counter = 1;
        int counter_helper = 0;
        int number;

        string temp;
        string s;

        while (getline(fin, s))
        {
            stringstream s_stream(s);
            switch (counter)
            {
            case 1:
                s_stream >> HP;
                s_stream >> level;
                s_stream >> remedy;
                s_stream >> maidenkiss;
                s_stream >> phoenixdown;
                rescue = -1;
                break;

            case 2:
                while (s_stream >> number)
                {
                    arr_events[arr_events_length] = number;
                    arr_events_length += 1;
                }
                break;

            case 3:
                while (getline(s_stream, temp, ','))
                {
                    arr_events_helper[counter_helper] = temp;
                    counter_helper += 1;
                }
                break;

            default:
                break;
            }
            counter += 1;
        }
    }

    // Other varibles
    // Enemy index start at 1
    float arr_baseDamage[6] = {-1, 1, 1.5, 4.5, 7.5, 9.5};
    int arr_fibos[16];

    int preLevel = 1;
    int maxLevel = 10; // Level cap at 10

    int preHP = 1;
    int maxHP = HP; // HP cap at maxHP = baseHP

    int frogEffect = 0;
    int tinyEffect = 0;

    // Misc
    int levelO = 0;
    int n1;
    int s1 = 0;
    string file_mush_ghost = arr_events_helper[0];
    string file_asclepius_pack = arr_events_helper[1];
    string file_merlin_pack = arr_events_helper[2];

    // Initialize arr_fibos
    for (int i = 0; i < 16; i++)
    {
        // Can use for-loop if need better time complexity
        arr_fibos[i] = calculateFibo(i + 1);
    }

    // Loop through each events
    int i = 0;
    bool end = false;

    // Read all the aditional files
    int arr_mush_ghost[100];
    int arr_mush_ghost_length;
    readFileMushGhost(file_mush_ghost, arr_mush_ghost, arr_mush_ghost_length);

    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    cout << "The previous are base stats." << endl;

    while ((i < arr_events_length) && (end == false))
    {
        // i + 1 = Event index
        // arr_events[i] = Event codes

        switch (arr_events[i])
        {

        case 0:
            // Bowser lose, win princess
            rescue = 1;
            end = true;
            break;

        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            // Meet regular enemies
            levelO = calculateLevelO(i);
            if (levelO == level)
            {
                break;
            }
            else
            {
                if (levelO < level)
                {
                    level += 1;
                    if (level > 10)
                    {
                        level = maxLevel;
                    }
                    break;
                }
                else
                {
                    // levelO > level
                    HP -= (arr_baseDamage[arr_events[i]] * levelO * 10);
                    // Check if the knight die
                    if (HP <= 0)
                    {
                        if (phoenixdown <= 0)
                        {
                            rescue = 0;
                            end = true;
                            break;
                        }
                        else
                        {
                            phoenixdown -= 1;
                            // Handle tiny effect
                            if (tinyEffect >= 1)
                            {
                                tinyEffect = 0;
                            }
                            HP = maxHP;
                            break;
                        }
                    }
                    break;
                }
            }
            break;

        case 6:
            // Meet Shaman
            if ((frogEffect >= 1) || (tinyEffect >= 1))
            {
                break;
            }

            levelO = calculateLevelO(i);
            if (levelO == level)
            {
                break;
            }
            else
            {
                if (levelO < level)
                {
                    level += 2;
                    if (level > 10)
                    {
                        level = maxLevel;
                    }
                    break;
                }
                else
                {
                    // levelO > level
                    preHP = HP;
                    if (HP <= 5)
                    {
                        HP = 1;
                    }
                    else
                    {
                        HP /= 5; // cpp automatically floor the result
                    }
                    tinyEffect = 4;
                    break;
                }
            }
            break;

        case 7:
            // Meet Siren Vajsh
            if ((frogEffect >= 1) || (tinyEffect >= 1))
            {
                break;
            }

            levelO = calculateLevelO(i);
            if (levelO == level)
            {
                break;
            }
            else
            {
                if (levelO < level)
                {
                    level += 2;
                    if (level > 10)
                    {
                        level = maxLevel;
                    }
                    break;
                }
                else
                {
                    // levelO > level
                    preLevel = level;
                    level = 1;
                    frogEffect = 4;
                    break;
                }
            }
            break;

        case 11:
            // Pick up MushMario
            n1 = (((level + phoenixdown) % 5) + 1) * 3;
            for (int i = 99; i > (99 - (2 * n1)); i -= 2)
            {
                s1 += i;
            }

            HP += s1 % 100;
            s1 = 0;
            if (HP > maxHP)
            {
                HP = maxHP;
            }
            break;

        case 12:
            // Pick up MushFib
            for (int i = 0; i < 16; i++)
            {
                if (arr_fibos[i] > HP)
                {
                    // Work just fine if HP == a Fibonanci Number
                    HP = arr_fibos[i - 1];
                    break;
                }
            }
            break;

        default:
            break;
        }

        // Handle effects
        if (tinyEffect >= 1)
        {
            // Handle potions usage
            if (remedy >= 1)
            {
                remedy -= 1;
                HP = preHP;
                tinyEffect = 0;
            }
            else
            {
                tinyEffect -= 1;
                if (tinyEffect == 0)
                {
                    HP *= 5;
                    // Cap at maxHP
                    if (HP > maxHP)
                    {
                        HP = maxHP;
                    }
                }
            }
        }

        if (frogEffect >= 1)
        {
            // Handle potions usage
            if (maidenkiss >= 1)
            {
                maidenkiss -= 1;
                level = preLevel;
                frogEffect = 0;
            }
            else
            {
                frogEffect -= 1;
                if (frogEffect == 0)
                {
                    level = preLevel;
                }
            }
        }

        // Check if we finish all the events
        if (i == arr_events_length - 1)
        {
            if (end != 1)
            {
                rescue = 1;
            }
        }

        // Continue to the next event
        i += 1;

        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    }
}