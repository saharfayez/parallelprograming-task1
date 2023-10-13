#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define USERS 50
#define username_length 20
#define pass_length 20

struct User
{
    char username[username_length];
    char password[pass_length];
};

struct User users[USERS];
int NUM_USERS = 0;

bool registerUser(const char *username, const char *password)
{
    if (NUM_USERS >= USERS)
    {
        printf("Maximum number of users reached.\n");
        return false;
    }

    for (int i = 0; i < NUM_USERS; i++)
    {
        if (strcmp(users[i].username, username) == 0)
        {
            printf("Username already exists.\n");
            return false;
        }
    }

    struct User newUser;
    strncpy(newUser.username, username, username_length);
    strncpy(newUser.password, password, pass_length);

    users[NUM_USERS++] = newUser;

    printf("Registration successful.\n");
    return true;
}

bool loginUser(const char *username, const char *password)
{
    for (int i = 0; i < NUM_USERS; i++)
    {
        if (strcmp(users[i].username, username) == 0)
        {
            if (strcmp(users[i].password, password) == 0)
            {
                printf("Login successful.\n");
                return true;
            }
            else
            {
                printf("Incorrect password.\n");
                return false;
            }
        }
    }

    printf("User not found.\n");
    return false;
}

int main()
{
    int choice;
    char username[username_length];
    char password[pass_length];

    while (true)
    {

        printf("for register enter 1 and for login enter 2");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            registerUser(username, password);
            break;

        case 2:
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            loginUser(username, password);
            break;
        default:
            printf("Enter 1 or 2 . Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}