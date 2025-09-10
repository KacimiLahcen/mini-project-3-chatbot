#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int ContainsKeyword(const char *sentence, const char *keyword)
{
    return strstr(sentence, keyword) != NULL;
}

int main()
{

    char UserAnswer[100];
    int exit = 0;

    char *positifs[] = {"happy", "well", "great"};
    char *negatifs[] = {"sad", "bad", "bored"};
    char *neutre[] = {"neutral", "okay"};

    char *PositifsReponses[] = {"That\"s awesome to hear !", "i am really glad you are feeling happy", "Happiness looks great on you!"};
    char *NegatifsReponses[] = {"I am sorry to hear that", "That sounds tough", "i am here for you if you need anything"};
    char *NeutreReponses[] = {"Thanks for sharing how you feel", "Thanks for letting me know"};

    srand(time(NULL));

    while (exit == 0)
    {
        printf("Chatbot : Hi sir, How do u feel Today ?  ( type 'exit' or 'quit' to quit)\n");
        printf("You : ");
        fgets(UserAnswer, sizeof(UserAnswer), stdin);

        UserAnswer[strcspn(UserAnswer, "\n")] = '\0';

        if (strcmp(UserAnswer, "exit") == 0 || strcmp(UserAnswer, "quit") == 0)
        {
            printf("Chatbot : Goodbye!\n");
            exit = 1;
            break;
        }

        int found = 0;

        for (int i = 0; i < sizeof(positifs) / sizeof(positifs[0]); i++)
        {
            if (ContainsKeyword(UserAnswer, positifs[i]))
            {
                int randomIndex = rand() % sizeof(positifs) / sizeof(positifs[0]);
                printf("Chatbot : ");
                printf("%s\n", PositifsReponses[randomIndex]); // Choose a response
                found = 1;
                break;
            }
        }
        if (!found)
        {
            for (int i = 0; i < sizeof(negatifs) / sizeof(negatifs[0]); i++)
            {
                if (ContainsKeyword(UserAnswer, negatifs[i]))
                {
                    int randomIndex = rand() % sizeof(negatifs) / sizeof(negatifs[0]);
                    printf("Chatbot : ");
                    printf("%s\n", NegatifsReponses[randomIndex]);
                    found = 1;
                    break;
                }
            }
        }
        if (!found)
        {
            for (int i = 0; i < sizeof(neutre) / sizeof(neutre[0]); i++)
            {
                if (ContainsKeyword(UserAnswer, neutre[i]))
                {
                    int randomIndex = rand() % sizeof(neutre) / sizeof(neutre[0]);
                    printf("Chatbot : ");
                    printf("%s\n", NeutreReponses[randomIndex]);
                    found = 1;
                    break;
                }
            }
        }
        if (!found)
        {
            printf("Chatbot : Sorry, I didn't understand that.\n");
        }
    }

    return 0;
}
