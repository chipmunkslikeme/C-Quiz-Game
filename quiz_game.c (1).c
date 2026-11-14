#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =====================================================
// FUNCTION TO CLEAR THE SCREEN
// Works on both Windows and Linux
// =====================================================

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


// =====================================================
// FUNCTION TO MOVE TO THE NEXT PAGE
// =====================================================

void nextPage()
{
    int ch;

    printf("\n\nPress ENTER to continue...");

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }

    getchar();

    clearScreen();
}



// =====================================================
// FUNCTION TO DISPLAY RULES
// =====================================================

void showRules()
{
    printf("The rules of the game are as follows:\n\n");

    printf("1. You have to select a topic and answer the questions in them.\n");

    printf("2. There will be 10 questions in each topic with 4 options each.\n");

    printf("3. You will have 3 lives.\n");

    printf("4. Right answer will pass you to the next question without affecting your lives.\n");

    printf("5. Wrong answer will take one life.\n");

    printf("6. Complete one topic and you get nothing. I mean, its for my C project bro.\n");

    printf("7. After writing these long ahh rules, I have to write even longer code and I don't wanna do that cuz its 2:46 am.\n");

    printf("8. Also, if you lose all lives, you die. DUh.\n");
}


// =====================================================
// MAIN PROGRAM
// =====================================================

int main()
{
    char username[100];

    int choice;
    int topic;

    int score = 0;
    int lives = 3;

    int moviesCompleted = 0;
    int sportsCompleted = 0;
    int technologyCompleted = 0;
    int mathematicsCompleted = 0;
    int completedTopics = 0;


    // =================================================
    // PAGE 1 - USERNAME
    // =================================================

    printf("========================================\n");
    printf("          THE QUIZ GAME\n");
    printf("========================================\n\n");

    printf("Enter your Username (upto 12 characters): ");

    scanf("%99s", username);


    // Check username length

    if (strlen(username) > 12)
    {
        printf("\nCan you not read or what....\n");
        printf("It literally said TWELVE CHARACTERS.\n");
        
        return 0;
    }


    // =================================================
    // PAGE 2 - WELCOME
    // =================================================

    nextPage();

    printf("Hi %s!\n\n", username);

    printf("Welcome to The Quiz Game.\n");

    printf("(Notice how theres no exclamation mark after 'Quiz Game'?)\n");

    printf("(Yea thats because I am not excited to make this.)\n");
    printf("That username is useless... It wont be used anywhere. I don't know why I did that\n");
    
    nextPage();


    // =================================================
    // PAGE 3 - RULES CHOICE
    // =================================================

    

    printf("SO, do you want to read the rules?\n\n");

    printf("1. Yes\n");
    printf("2. No\n\n");

    printf("Enter your choice: ");

    scanf("%d", &choice);


    // =================================================
    // PAGE 4 - RULES
    // =================================================

    nextPage();


    if (choice == 1)
    {
        printf("Great! There you go.\n");

        showRules();
    }

    else if (choice == 2)
    {
        printf("Yea no. You are still reading the rules.\n");

        printf("Why did I waste time writing it if you could skip it?\n\n");

        showRules();
    }

    else
    {
        printf("Invalid choice!\n");

        printf("Stop testing the code, I wrote it alright. AI did but I did too...\n");

        printf("You are going to read the rules now for choosing the wrong option.\n\n");

        showRules();
    }



    // =================================================
    // PAGE 5 - TOPIC SELECTION
    // =================================================

    while (lives > 0)
    {
        nextPage();

        if (completedTopics == 4)
        {
            clearScreen();
            printf("Looks like you have allthe time in the world.. look at you, wasting time on a prototype C project and do something useful. Thats the end of our game.. Thanks for playing yay\n");
            return 0;
        }

        printf("Time to choose a topic.\n\n");

        if (!moviesCompleted)
            printf("1. Movies\n");
        else
            printf("1. ~~Movies~~ (COMPLETED)\n");

        if (!sportsCompleted)
            printf("2. (KBC style)Sports\n");
        else
            printf("2. ~~(KBC style)Sports~~ (COMPLETED)\n");

        if (!technologyCompleted)
            printf("3. Technology\n");
        else
            printf("3. ~~Technology~~ (COMPLETED)\n");

        if (!mathematicsCompleted)
            printf("4. (our FAVOURITE subject) Engineering Mathematics\n");
        else
            printf("4. ~~(our FAVOURITE subject) Engineering Mathematics~~ (COMPLETED)\n");

        printf("\nCurrent Score: %d\n", score);
        printf("Lives remaining: %d\n", lives);
        printf("\nEnter your choice: ");
        scanf("%d", &topic);

        if ((topic == 1 && moviesCompleted) ||
            (topic == 2 && sportsCompleted) ||
            (topic == 3 && technologyCompleted) ||
            (topic == 4 && mathematicsCompleted))
        {
            printf("\nThat topic is already crossed off! Choose another one.\n");
            nextPage();
            continue;
        }

        // =================================================
        // TOPIC RESULT
        // =================================================

        nextPage();

        switch (topic)
        {
            case 1:
                printf("You selected Movies... Good yaar.\n");
                break;

            case 2:
                printf("You selected Sports... I am asthamatic.So, JUST THIS ONCE, I'll let Amit ji takeover. Don't miss me too much tho.\n");
                break;

            case 3:
                printf("You selected Technology... I did too.. Look where it got me.\n");
                break;

            case 4:
                printf("You selected Engineering Mathematics (our FAVOURITE subject).\n");
                break;

            default:
                printf("Invalid topic!\n");
                printf("STOP TESTING THE CODE.\n");
                continue;
        }

        printf("ANYWAYS, here's your FIRST question. Don't mess it up.\n");
        nextPage();

// =====================================================
    // MOVIES QUIZ
    // =====================================================

    if (topic == 1)
    {
        int answer;
        int i;

        const char *questions[10] = {
            "Who played Iron Man in the Marvel Cinematic Universe?",
            "Which movie features the song 'Let It Go'?",
            "What is the name of the wizarding school in Harry Potter?",
            "Who directed the movie Titanic (1997)?",
            "Which is the fictional African country in Black Panther?",
            "In Finding Nemo, what type of fish is Nemo?",
            "Which actor played Jack in Titanic?",
            "What is the name of the cowboy in Toy Story?",
            "Which movie features the character Darth Vader?",
            "In The Lion King, what is Simba's father's name?"
        };

        const char *options[10][4] = {
            {"Chris Evans", "Robert Downey Jr.", "Chris Hemsworth", "Mark Ruffalo"},
            {"Moana", "Tangled", "Frozen", "Brave"},
            {"Nevermore Academy", "Hogwarts", "Camp Half-Blood", "Shiz University"},
            {"Steven Spielberg", "James Cameron", "Christopher Nolan", "Peter Jackson"},
            {"Genovia", "Zamunda", "Wakanda", "Elbonia"},
            {"Goldfish", "Clownfish", "Blue tang", "Angelfish"},
            {"Leonardo DiCaprio", "Brad Pitt", "Tom Cruise", "Matt Damon"},
            {"Buzz Lightyear", "Jessie", "Woody", "Bullseye"},
            {"Star Trek", "Star Wars", "Guardians of the Galaxy", "Dune"},
            {"Mufasa", "Scar", "Rafiki", "Zazu"}
        };

        int correct[10] = {2, 3, 2, 2, 3, 2, 1, 3, 2, 1};

        printf("========================================\n");
        printf("          THE MOVIES QUIZ\n");
        printf("========================================\n\n");

        for (i = 0; i < 10 && lives > 0; i++)
        {
            printf("Question %d:\n\n", i + 1);
            printf("%s\n\n", questions[i]);

            for (int j = 0; j < 4; j++)
                printf("%d. %s\n", j + 1, options[i][j]);

            printf("\nLives remaining: %d\n", lives);
            printf("Enter your answer (1-4): ");
            scanf("%d", &answer);

            if (answer == correct[i])
            {
                printf("\nCORRECT ANSWER! Look at you, knowing things.\n");
                score += 100;
            }
            else
            {
                lives--;
                printf("\nWRONG ANSWER! The cinema is disappointed in you.\n");
                printf("Correct answer: %d. %s\n", correct[i], options[i][correct[i] - 1]);
                printf("Lives remaining: %d\n", lives);
            }

            if (i < 9 && lives > 0)
                nextPage();
        }

        printf("\n========================================\n");
        printf("              MOVIES QUIZ OVER\n");
        printf("========================================\n");
        printf("Player: %s\n", username);
        printf("Final Score: %d/10\n", score);

        if (score == 10)
            printf("Perfect score! Are you secretly a movie database?\n");
        else if (lives == 0)
            printf("You ran out of lives. Maybe let the actors do the acting next time.\n");
        else
            printf("Quiz complete! Not bad for someone who probably watches movies with subtitles off.\n");

        printf("========================================\n");
    }


        if (lives > 0 && !moviesCompleted) { moviesCompleted = 1; completedTopics++; }

// =====================================================
// TECHNOLOGY QUIZ
// =====================================================

if (topic == 3)
{
    int answer;


    // =================================================
    // QUESTION 1
    // =================================================

    printf("==============================\n");
    printf("       TECHNOLOGY QUIZ\n");
    printf("==============================\n\n");

    printf("Question 1:\n\n");

    printf("What does CPU stand for?\n\n");

    printf("1. Central Processing Unit\n");
    printf("2. Computer Power Unit\n");
    printf("3. Central Program Utility\n");
    printf("4. Control Processing User\n\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 1)
    {
        printf("\nCORRECT ANSWER!\n");
        printf("YOU CAN PASS TO THE NEXT QUESTION.\n");
        score += 100;
    }
    else
    {
        lives--;

        printf("\nWRONG ANSWER!\n");
        printf("You lost 1 life.\n");
        printf("Lives remaining: %d\n", lives);
    }

    nextPage();


    // =================================================
    // QUESTION 2
    // =================================================

    printf("==============================\n");
    printf("       TECHNOLOGY QUIZ\n");
    printf("==============================\n\n");

    printf("Question 2:\n\n");

    printf("Which of these is NOT an input device?\n\n");

    printf("1. Keyboard\n");
    printf("2. Mouse\n");
    printf("3. Monitor\n");
    printf("4. Microphone\n\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 3)
    {
        printf("\nCORRECT ANSWER!\n");
        printf("YOU CAN PASS TO THE NEXT QUESTION.\n");
        score += 100;
    }
    else
    {
        lives--;

        printf("\nWRONG ANSWER!\n");
        printf("You lost 1 life.\n");
        printf("Lives remaining: %d\n", lives);
    }

    nextPage();


    // =================================================
    // QUESTION 3
    // =================================================

    printf("==============================\n");
    printf("       TECHNOLOGY QUIZ\n");
    printf("==============================\n\n");

    printf("Question 3:\n\n");

    printf("What does a computer need to work?\n\n");

    printf("1. Food\n");
    printf("2. Electricity\n");
    printf("3. Water\n");
    printf("4. Sleep\n\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 2)
    {
        printf("\nCORRECT ANSWER!\n");
        printf("YOU CAN PASS TO THE NEXT QUESTION.\n");
        score += 100;
    }
    else
    {
        lives--;

        printf("\nWRONG ANSWER!\n");
        printf("You lost 1 life.\n");
        printf("Lives remaining: %d\n", lives);
    }

    nextPage();


    // =================================================
    // QUESTION 4
    // =================================================

    printf("==============================\n");
    printf("       TECHNOLOGY QUIZ\n");
    printf("==============================\n\n");

    printf("Question 4:\n\n");

    printf("Which of these is used to browse the internet?\n\n");

    printf("1. Calculator\n");
    printf("2. Notepad\n");
    printf("3. Web browser\n");
    printf("4. Paint\n\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 3)
    {
        printf("\nCORRECT ANSWER!\n");
        printf("YOU CAN PASS TO THE NEXT QUESTION.\n");
        score += 100;
    }
    else
    {
        lives--;

        printf("\nWRONG ANSWER!\n");
        printf("You lost 1 life.\n");
        printf("Lives remaining: %d\n", lives);
    }

    nextPage();


    // =================================================
    // QUESTION 5
    // =================================================

    printf("==============================\n");
    printf("       TECHNOLOGY QUIZ\n");
    printf("==============================\n\n");

    printf("Question 5:\n\n");

    printf("What does USB stand for?\n\n");

    printf("1. Universal Serial Bus\n");
    printf("2. United System Board\n");
    printf("3. Universal Storage Box\n");
    printf("4. User System Backup\n\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 1)
    {
        printf("\nCORRECT ANSWER!\n");
        printf("YOU CAN PASS TO THE NEXT QUESTION.\n");
        score += 100;
    }
    else
    {
        lives--;

        printf("\nWRONG ANSWER!\n");
        printf("You lost 1 life.\n");
        printf("Lives remaining: %d\n", lives);
    }

    nextPage();


    // =================================================
    // QUESTION 6
    // =================================================

    printf("==============================\n");
    printf("       TECHNOLOGY QUIZ\n");
    printf("==============================\n\n");

    printf("Question 6:\n\n");

    printf("Which key is used to create a space between words?\n\n");

    printf("1. Enter\n");
    printf("2. Shift\n");
    printf("3. Spacebar\n");
    printf("4. Backspace\n\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 3)
    {
        printf("\nCORRECT ANSWER!\n");
        printf("YOU CAN PASS TO THE NEXT QUESTION.\n");
        score += 100;
    }
    else
    {
        lives--;

        printf("\nWRONG ANSWER!\n");
        printf("You lost 1 life.\n");
        printf("Lives remaining: %d\n", lives);
    }

    nextPage();


    // =================================================
    // QUESTION 7
    // =================================================

    printf("==============================\n");
    printf("       TECHNOLOGY QUIZ\n");
    printf("==============================\n\n");

    printf("Question 7:\n\n");

    printf("What is the brain of a computer?\n\n");

    printf("1. Monitor\n");
    printf("2. CPU\n");
    printf("3. Keyboard\n");
    printf("4. Mouse\n\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 2)
    {
        printf("\nCORRECT ANSWER!\n");
        printf("YOU CAN PASS TO THE NEXT QUESTION.\n");
        score += 100;
    }
    else
    {
        lives--;

        printf("\nWRONG ANSWER!\n");
        printf("You lost 1 life.\n");
        printf("Lives remaining: %d\n", lives);
    }

    nextPage();


    // =================================================
    // QUESTION 8
    // =================================================

    printf("==============================\n");
    printf("       TECHNOLOGY QUIZ\n");
    printf("==============================\n\n");

    printf("Question 8:\n\n");

    printf("Which of these is an operating system?\n\n");

    printf("1. Google Chrome\n");
    printf("2. Microsoft Word\n");
    printf("3. Windows\n");
    printf("4. YouTube\n\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 3)
    {
        printf("\nCORRECT ANSWER!\n");
        printf("YOU CAN PASS TO THE NEXT QUESTION.\n");
        score += 100;
    }
    else
    {
        lives--;

        printf("\nWRONG ANSWER!\n");
        printf("You lost 1 life.\n");
        printf("Lives remaining: %d\n", lives);
    }

    nextPage();


    // =================================================
    // QUESTION 9
    // =================================================

    printf("==============================\n");
    printf("       TECHNOLOGY QUIZ\n");
    printf("==============================\n\n");

    printf("Question 9:\n\n");

    printf("What happens when you press Ctrl + C?\n\n");

    printf("1. The computer shuts down\n");
    printf("2. The selected text is copied\n");
    printf("3. The screen turns black\n");
    printf("4. The file is deleted\n\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 2)
    {
        printf("\nCORRECT ANSWER!\n");
        printf("YOU CAN PASS TO THE NEXT QUESTION.\n");
        score += 100;
    }
    else
    {
        lives--;

        printf("\nWRONG ANSWER!\n");
        printf("You lost 1 life.\n");
        printf("Lives remaining: %d\n", lives);
    }

    nextPage();
    
    // =================================================
    // TRANSITION TO QUESTION 10
    // =================================================

    printf("U think all of this is too easy huh.\n");
    printf("I see..\n\n");

    nextPage();


    // =================================================
    // QUESTION 10 - GATE LEVEL
    // =================================================

    printf("========================================\n");
    printf("           FINAL QUESTION\n");
    printf("========================================\n\n");

    printf("Consider the following C program:\n\n");

    printf("#include <stdio.h>\n\n");

    printf("void exchange(int *a, int *b) {\n");
    printf("    int temp;\n");
    printf("    temp = *a;\n");
    printf("    *a = *b;\n");
    printf("    *b = temp;\n");
    printf("}\n\n");

    printf("int main() {\n");
    printf("    char *prt[] = {\"books\", \"data\", \"structures\", \"through\", \"C\"};\n");
    printf("    char **ptr[] = {prt+3, prt+2, prt+1, prt};\n");
    printf("    char ***p = ptr;\n\n");

    printf("    printf(\"%%s \", **++p);\n");
    printf("    printf(\"%%s \", *--*++p + 3);\n");
    printf("    printf(\"%%s \", *p[-2] + 3);\n");
    printf("    printf(\"%%s \\n\", p[-1][-1] + 1);\n\n");

    printf("    return 0;\n");
    printf("}\n\n");

    printf("What will be the output of this program?\n\n");

    printf("1. structures data through C\n");
    printf("2. through books data structures\n");
    printf("3. structures ks ough ata\n");
    printf("4. data structures books through\n\n");

    printf("Enter your answer: ");
    scanf("%d", &answer);

    printf("\n");

    if (answer >= 1 && answer <= 4)
    {
        lives--;

        printf("WRONG ANSWER!\n");
        printf("You lost 1 life.\n");
        printf("Lives remaining: %d\n", lives);
        printf("\nThere was no correct option. Congratulations.\n");
    }
    else
    {
        printf("Invalid choice!\n");
    }





    } // End of Technology quiz (topic == 3)

    // =====================================================
    
if (lives > 0 && !technologyCompleted) { technologyCompleted = 1; completedTopics++; }

// SPORTS QUIZ - KBC STYLE
    // =====================================================

    if (topic == 2)
    {
        int answer;

        // =================================================
        // QUESTION 1
        // =================================================

        printf("=========================================================================\n");
        printf("         KAUN BANEGA CROREPATI: THE PASSIVE-AGGRESSIVE SPORTS QUIZ\n");
        printf("=========================================================================\n\n");

        printf("Amit Ji: Question 1 is on your screen. Do not overthink this, please:\n\n");
        printf("Question 1 (Cricket):\n");
        printf("How many runs do you get if a batsman hits the cricket ball directly over the boundary rope without touching the ground?\n\n");
        printf("1. 4\n");
        printf("2. 6\n");
        printf("3. 1\n");
        printf("4. 0\n\n");

        printf("Your Answer: ");
        scanf("%d", &answer);

        if (answer == 2)
        {
            printf("\nAmit Ji: Sahi jawaab! Brilliant. At least your basic schooling paid off.\n");
            score += 100;
        }
        else
        {
            lives--;
            printf("\nAmit Ji: Wow. Galat jawaab. Honestly, Google is disappointed in you right now.\n");
            printf("Remaining Lives: %d\n", lives);
        }

        nextPage();

        // =================================================
        // QUESTION 2
        // =================================================

        printf("=========================================================================\n");
        printf("Amit Ji: Question 2. Keep your focus sharp, don't choke already:\n\n");

        printf("Question 2 (Kabaddi):\n");
        printf("What word must a raider continuously chant out loud when crossing into the opponent's half?\n\n");
        printf("1. Kabaddi\n");
        printf("2. Raider\n");
        printf("3. Defend\n");
        printf("4. Out\n\n");

        printf("Your Answer: ");
        scanf("%d", &answer);

        if (answer == 1)
        {
            printf("\nAmit Ji: Sahi jawaab! Brilliant. At least your basic schooling paid off.\n");
            score += 100;
        }
        else
        {
            lives--;
            printf("\nAmit Ji: Wow. Galat jawaab. Honestly, Google is disappointed in you right now.\n");
            printf("Remaining Lives: %d\n", lives);
        }

        nextPage();

        // =================================================
        // QUESTION 3
        // =================================================

        printf("=========================================================================\n");
        printf("Amit Ji: Third question... hopefully, this is matching your intellectual level:\n\n");

        printf("Question 3 (Cricket Equipment):\n");
        printf("What does a cricket batsman hold in their hands to hit the ball?\n\n");
        printf("1. Racket\n");
        printf("2. Bat\n");
        printf("3. Club\n");
        printf("4. Stick\n\n");

        printf("Your Answer: ");
        scanf("%d", &answer);

        if (answer == 2)
        {
            printf("\nAmit Ji: Sahi jawaab! Brilliant. At least your basic schooling paid off.\n");
            score += 100;
        }
        else
        {
            lives--;
            printf("\nAmit Ji: Wow. Galat jawaab. Honestly, Google is disappointed in you right now.\n");
            printf("Remaining Lives: %d\n", lives);
        }

        nextPage();

        // =================================================
        // QUESTION 4
        // =================================================

        printf("=========================================================================\n");
        printf("Amit Ji: Question 4... keeping it simple for you:\n\n");

        printf("Question 4 (Badminton):\n");
        printf("Instead of a round ball, what unique, feathered object do players hit back and forth?\n\n");
        printf("1. Puck\n");
        printf("2. Shuttlecock\n");
        printf("3. Frisbee\n");
        printf("4. Marble\n\n");

        printf("Your Answer: ");
        scanf("%d", &answer);

        if (answer == 2)
        {
            printf("\nAmit Ji: Sahi jawaab! Brilliant. At least your basic schooling paid off.\n");
            score += 100;
        }
        else
        {
            lives--;
            printf("\nAmit Ji: Wow. Galat jawaab. Honestly, Google is disappointed in you right now.\n");
            printf("Remaining Lives: %d\n", lives);
        }

        nextPage();

        // =================================================
        // QUESTION 5
        // =================================================

        printf("=========================================================================\n");
        printf("Amit Ji: We are halfway there. Time to prove you actually follow sports:\n\n");

        printf("Question 5 (Field Hockey):\n");
        printf("What object do players use to move the ball and score goals?\n\n");
        printf("1. Hockey Stick\n");
        printf("2. Bat\n");
        printf("3. Hands\n");
        printf("4. Feet\n\n");

        printf("Your Answer: ");
        scanf("%d", &answer);

        if (answer == 1)
        {
            printf("\nAmit Ji: Sahi jawaab! Brilliant. At least your basic schooling paid off.\n");
            score += 100;
        }
        else
        {
            lives--;
            printf("\nAmit Ji: Wow. Galat jawaab. Honestly, Google is disappointed in you right now.\n");
            printf("Remaining Lives: %d\n", lives);
        }

        nextPage();

        // =================================================
        // QUESTION 6
        // =================================================

        printf("=========================================================================\n");
        printf("Amit Ji: Question 6... let's see if you know your legends:\n\n");

        printf("Question 6 (Cricket Teams):\n");
        printf("Which team did MS Dhoni captain for years in the IPL?\n\n");
        printf("1. Mumbai Indians\n");
        printf("2. Chennai Super Kings (CSK)\n");
        printf("3. Royal Challengers Bengaluru\n");
        printf("4. Kolkata Knight Riders\n\n");

        printf("Your Answer: ");
        scanf("%d", &answer);

        if (answer == 2)
        {
            printf("\nAmit Ji: Sahi jawaab! Brilliant. At least your basic schooling paid off.\n");
            score += 100;
        }
        else
        {
            lives--;
            printf("\nAmit Ji: Wow. Galat jawaab. Honestly, Google is disappointed in you right now.\n");
            printf("Remaining Lives: %d\n", lives);
        }

        nextPage();

        // =================================================
        // QUESTION 7
        // =================================================

        printf("=========================================================================\n");
        printf("Amit Ji: Question 7. Computer ji, let's test their basic childhood memories:\n\n");

        printf("Question 7 (Board Games):\n");
        printf("Which indoor game involves flicking a striker disc to pocket wooden carrom men?\n\n");
        printf("1. Chess\n");
        printf("2. Carrom\n");
        printf("3. Ludo\n");
        printf("4. Monopoly\n\n");

        printf("Your Answer: ");
        scanf("%d", &answer);

        if (answer == 2)
        {
            printf("\nAmit Ji: Sahi jawaab! Brilliant. At least your basic schooling paid off.\n");
            score += 100;
        }
        else
        {
            lives--;
            printf("\nAmit Ji: Wow. Galat jawaab. Honestly, Google is disappointed in you right now.\n");
            printf("Remaining Lives: %d\n", lives);
        }

        nextPage();

        // =================================================
        // QUESTION 8
        // =================================================

        printf("=========================================================================\n");
        printf("Amit Ji: Question 8. Can we match standard logic here?\n\n");

        printf("Question 8 (Cricket):\n");
        printf("How many wickets must a bowling team take to completely dismiss an entire batting team?\n\n");
        printf("1. 10\n");
        printf("2. 11\n");
        printf("3. 6\n");
        printf("4. 5\n\n");

        printf("Your Answer: ");
        scanf("%d", &answer);

        if (answer == 1)
        {
            printf("\nAmit Ji: Sahi jawaab! Brilliant. At least your basic schooling paid off.\n");
            score += 100;
        }
        else
        {
            lives--;
            printf("\nAmit Ji: Wow. Galat jawaab. Honestly, Google is disappointed in you right now.\n");
            printf("Remaining Lives: %d\n", lives);
        }

        nextPage();

        // =================================================
        // QUESTION 9
        // =================================================

        printf("=========================================================================\n");
        printf("Amit Ji: Question 9. The final step before the real drama begins:\n\n");

        printf("Question 9 (Traditional Games):\n");
        printf("In Kho-Kho, what do chasing players do to clear the way for a teammate?\n\n");
        printf("1. Give a high-five\n");
        printf("2. Tap a teammate on the back and shout 'Kho!'\n");
        printf("3. Throw a ball\n");
        printf("4. Blow a whistle\n\n");

        printf("Your Answer: ");
        scanf("%d", &answer);

        if (answer == 2)
        {
            printf("\nAmit Ji: Sahi jawaab! Brilliant. At least your basic schooling paid off.\n");
            score += 100;
        }
        else
        {
            lives--;
            printf("\nAmit Ji: Wow. Galat jawaab. Honestly, Google is disappointed in you right now.\n");
            printf("Remaining Lives: %d\n", lives);
        }

        nextPage();

        // =================================================
        // QUESTION 10 - KBC TRAP
        // =================================================

        if (lives > 0)
        {
            printf("=========================================================================\n");
            printf("Amit Ji: Oh-ho! %s ji... you think this is too easy huh.\n", username);
            printf("         You thought you were absolute royalty sailing through this quiz?\n");
            printf("Computer Ji: *Plays dramatic villain suspense background music*\n\n");

            nextPage();

            while (lives > 0)
            {
                printf("=========================================================================\n");
                printf("Amit Ji: Question 10... for 7 Crore. Let's see if you actually have a brain or just pure luck:\n\n");

                printf("Question 10 (Expert Sports History):\n");
                printf("In the 1952 Helsinki Olympics, what was the exact atmospheric pressure (in hPa)\n");
                printf("inside the football bladder during India's match against Yugoslavia, and how many stitches\n");
                printf("were sewn on K. D. Jadhav's wrestling singlet?\n\n");
                printf("1. 1013.25 hPa and exactly 42 stitches\n");
                printf("2. 1008.40 hPa and exactly 38 stitches\n");
                printf("3. 1020.12 hPa and exactly 51 stitches\n");
                printf("4. 995.60 hPa and exactly 47 stitches\n\n");
                printf("Current Remaining Lives: %d\n", lives);

                printf("\nYour Answer: ");
                scanf("%d", &answer);

                lives--;

                printf("\nAmit Ji: Lock kar diya jaye? Let's check if your wild guess holds any ground.\n");
                nextPage();

                printf("Amit Ji: Afsos! Completely and utterly incorrect!\n");

                if (lives > 0)
                {
                    printf("But don't give up! Computer ji is giving you another chance. Try another option!\n");
                    printf("Remaining Lives: %d\n", lives);
                }
                else
                {
                    printf("And with that, your very last life is completely GONE!\n");
                    printf("Remaining Lives: %d\n", lives);
                }

                nextPage();
            }
        }

        // =================================================
        // FINAL GAME OVER SCREEN
        // =================================================

        printf("=========================================================================\n");
        printf("                     KHATAM, TATA, BYE BYE!\n");
        printf("=========================================================================\n\n");

        printf("Amit Ji: *Claps slowly* Deviyon aur sajjano, standard operational protocol ke mutabik,\n");
        printf("         ab waqt aa gaya hai sach batane ka. %s ji, you were absolutely fooled!\n", username);
        printf("         Computer ji and I completely made up Question 10. Every single option (1, 2, 3, 4)\n");
        printf("         was intentionally incorrect from the start! The game scammed you for the plot.\n");
        printf("         You were trapped in a loop designed to steal your lives, and you fell for it!\n\n");

        if (score == 9)
        {
            printf("Amit Ji: Well khele %s ji. You got 9 correct, but Question 10 completely\n", username);
            printf("         made an absolute clown out of you. Final Score: %d/10. Hilarious run!\n", score);
        }
        else
        {
            printf("Amit Ji: %s ji, you ran out of lives on simple questions. Tragic.\n", username);
            printf("         Final Score: %d/10. Please turn off the computer, accept the scam, and touch some grass.\n", score);
        }

        printf("=========================================================================\n");
    }


        if (lives > 0 && !sportsCompleted) { sportsCompleted = 1; completedTopics++; }


    // =====================================================
    // ENGINEERING MATHEMATICS QUIZ
    // =====================================================

    if (topic == 4)
    {
        int answer;
        int i;

        const char *questions[10] = {
            "If 2x + 5 = 13, what is the value of x?",
            "What is 15% of 200?",
            "Using pi = 22/7, what is the area of a circle with radius 7 cm?",
            "What are the roots of x^2 - 5x + 6 = 0?",
            "What is the value of sin(30 degrees)?",
            "If A = [[1,2,3],[0,1,4],[5,6,0]], what is det(A)?",
            "If z = (1 + i)^8, where i^2 = -1, what is the value of z?",
            "If y = (x^2 + 1)^(sin x), which is dy/dx?",
            "Evaluate lim(x->0) [e^x - 1 - x] / x^2.",
            "For A = [[1,1,1],[1,2,3],[1,3,6]], what is A^(-1)?"
        };

        const char *options[10][4] = {
            {"2", "3", "4", "5"},
            {"20", "25", "30", "35"},
            {"44 cm^2", "154 cm^2", "308 cm^2", "616 cm^2"},
            {"1 and 6", "2 and 3", "-2 and -3", "3 and 5"},
            {"0", "1/2", "sqrt(3)/2", "1"},
            {"-1", "0", "1", "6"},
            {"8", "16", "-16", "8i"},
            {
                "(x^2+1)^(sin x) [2x sin x/(x^2+1) + cos x ln(x^2+1)]",
                "(x^2+1)^(sin x) [2x cos x/(x^2+1) + sin x ln(x^2+1)]",
                "sin(x)(x^2+1)^(sin x - 1)",
                "2x sin(x)"
            },
            {"0", "1/2", "1", "2"},
            {
                "[[3,-3,1],[-3,5,-2],[1,-2,1]]",
                "[[1,1,1],[1,2,3],[1,3,6]]",
                "[[3,3,1],[3,5,2],[1,2,1]]",
                "[[2,-3,1],[-3,4,-2],[1,-2,2]]"
            }
        };

        int correct[10] = {3, 3, 2, 2, 2, 3, 2, 1, 2, 1};

        printf("=============================================================\n");
        printf("       ENGINEERING MATHEMATICS (OUR FAVOURITE SUBJECT)\n");
        printf("=============================================================\n\n");
        printf("First 5 questions: easy warm-up.\n");
        printf("Last 5 questions: ENGINEERING LEVEL. Good luck.\n");

        nextPage();

        for (i = 0; i < 10 && lives > 0; i++)
        {
            if (i == 5)
            {
                printf("=============================================================\n");
                printf("              ENGINEERING LEVEL ACTIVATED\n");
                printf("=============================================================\n\n");
                printf("Matrices. Complex Numbers. Differentiation. Limits.\n");
                printf("You asked for tough. You got tough.\n");
                nextPage();
            }

            printf("Question %d:\n\n", i + 1);
            printf("%s\n\n", questions[i]);

            for (int j = 0; j < 4; j++)
                printf("%d. %s\n", j + 1, options[i][j]);

            printf("\nScore: %d     Lives remaining: %d\n", score, lives);
            printf("Enter your answer (1-4): ");
            scanf("%d", &answer);

            if (answer < 1 || answer > 4)
            {
                printf("\nInvalid choice! No life lost.\n");
            }
            else if (answer == correct[i])
            {
                score += 100;
                printf("\nCORRECT ANSWER!\n");
                printf("YOU CAN PASS TO THE NEXT QUESTION.\n");
                printf("+100 points. Mathematics has approved your existence.\n");
            }
            else
            {
                lives--;
                printf("\nWRONG ANSWER!\n");
                printf("You lost 1 life.\n");
                printf("Correct answer: %d. %s\n", correct[i], options[i][correct[i] - 1]);
                printf("Lives remaining: %d\n", lives);
            }

            if (i < 9 && lives > 0)
                nextPage();
        }

        if (lives > 0 && !mathematicsCompleted) { mathematicsCompleted = 1; completedTopics++; }

        printf("\n=============================================================\n");
        printf("              ENGINEERING MATHEMATICS OVER\n");
        printf("=============================================================\n");
        printf("Current Score: %d\n", score);
        printf("Lives Remaining: %d\n", lives);
    }

        if (completedTopics == 4)
        {
            nextPage();
            printf("Looks like you have allthe time in the world.. look at you, wasting time on a prototype C project and do something useful. Thats the end of our game.. Thanks for playing yay\n");
            return 0;
        }

        if (lives == 0)
        {
            clearScreen();
            printf("\n====================================================\n");
            printf("                    GAME OVER\n");
            printf("====================================================\n\n");
            printf("Player: %s\n", username);
            printf("Final Score: %d\n", score);
            printf("Topics Completed: %d/4\n", completedTopics);
            printf("\nYou lost all your lives.\n");
            printf("====================================================\n");
            return 0;
        }

        nextPage();

        printf("Do you want to play again?\n\n");
        printf("1. Yes, choose another topic\n");
        printf("2. No, exit the game\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nAlright. Your current score and lives stay with you.\n");
            printf("You can choose any topic again.\n");
        }
        else if (choice == 2)
        {
            clearScreen();
            printf("====================================================\n");
            printf("                    GAME EXITED\n");
            printf("====================================================\n\n");
            printf("Player: %s\n", username);
            printf("Score: %d\n", score);
            printf("Lives Remaining: %d\n", lives);
            printf("\nTY FOR PLAYING OUR GAME.. GIVE US FULL MARKS PLS\n");
            printf("====================================================\n");
            return 0;
        }
        else
        {
            printf("\nInvalid choice!\n");
            printf("STOP TESTING THE CODE.\n");
        }

    }

    return 0;
}
