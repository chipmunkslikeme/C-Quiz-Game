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

    nextPage();

    printf("Time to choose a topic.\n\n");

    printf("1. Movies\n");
    printf("2. Sports\n");
    
    printf("3. Politics\n");
    printf("4. Technology\n");
    printf("5. (super secret topic) BVDU\n");
    
    
    

    printf("Enter your choice: ");

    scanf("%d", &topic);


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
            printf("You selected Sports... I am asthamatic.\n");
            break;

        case 3:
            printf("You selected Politics...Really?! Who chooses THAT boring stuff here. Go back to 80's UNC\n");
            break;

        case 4:
            printf("You selected Technology... I did too.. Look where it got me.\n");
            break;
        
        case 5:
            printf("You selected BVDU. Why would ANYONE select that.\n");
            break;

        default:
            printf("Invalid topic!\n");
            printf("STOP TESTING THE CODE.\n");
            break;
    }
    
    printf("ANYWAYS, here's your FIRST question. Don't mess it up.\n");
    nextPage();   // <-- ADD THIS
    
    // =====================================================
// TECHNOLOGY QUIZ
// =====================================================

if (topic == 4)
{
    int answer;
    int lives = 3;


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




    return 0;
}
}