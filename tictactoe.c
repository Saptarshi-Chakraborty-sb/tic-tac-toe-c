#include <stdio.h>

int main()
{
    char values[] = "123456789", turn = 'X';
    int position, allFilled = 0, i, again = 0;

    while (1)
    {
// Detect machine type and run below command in terminal to clear terminal
#ifdef _WIN32
        system("cls");
#elif __linux__
        system("clear");
#elif __APPLE__
        system("clear");
#endif
        printf("\n -->  TIC - TAC - TOE  <--\n");
        // Game Running
        while (1)
        {

            printf("\n----------------------------\n");
            printf("\t %c | %c | %c\n", values[0], values[1], values[2]);
            printf("\t-----------\n");
            printf("\t %c | %c | %c\n", values[3], values[4], values[5]);
            printf("\t-----------\n");
            printf("\t %c | %c | %c\n", values[6], values[7], values[8]);
            printf("----------------------------\n");

            // Check if there is a Winner
            if (
                ((values[0] == values[1]) && (values[1] == values[2])) ||
                ((values[3] == values[4]) && (values[4] == values[5])) ||
                ((values[6] == values[7]) && (values[7] == values[8])) ||
                ((values[0] == values[3]) && (values[3] == values[6])) ||
                ((values[1] == values[4]) && (values[4] == values[7])) ||
                ((values[2] == values[5]) && (values[5] == values[8])) ||
                ((values[0] == values[4]) && (values[4] == values[8])) ||
                ((values[2] == values[4]) && (values[4] == values[6])))
            {
                printf(" ---->  '%c' is WINNER  <----\n", (turn == 'X') ? 'O' : 'X');
                break;
            }

            // Check if all Position is Filled
            for (i = 0; i < 9; i++)
            {
                if (values[i] == 'X' || values[i] == 'O') // check if avary box is filled with X or O
                    allFilled++;
            }

            if (allFilled == 9)
            {
                printf("    --->  Match Draw  <---\n");
                break;
            }
            else
                allFilled = 0;

            printf("\t\b###  TURN: %c  ###\n", turn);
            printf("Enter a Position Number >> ");
            scanf("%d", &position);

            // If invalid Position Number
            if (position <= 0 || position > 9)
            {
                system("cls");
                printf(" !!! Invalid Position Number !!!\n");
                continue;
            }

            // If Position Number is already filled
            if (values[position - 1] == 'X' || values[position - 1] == 'O')
            {
                system("cls");
                printf(" !!! That Position is Already Filled !!!\n");
                continue;
            }

            // If Position Number is valid
            values[position - 1] = turn;

            turn = (turn == 'X') ? 'O' : 'X'; // Alternet the turn
        }

        // Play
        printf("\n");
        printf("  =========================== \n");
        printf("  |  Play Again : 0 (Zero)  | \n");
        printf("  |  Exit : Any Other Key   | \n");
        printf("  =========================== \n");
        printf("\n >> ");
        scanf("%d", &again);

        if (again == 0) // Game Reset
        {
            for (i = 0; i < 9; i++)
                values[i] = '0' + (i + 1);
            turn = 'X';
            allFilled = 0;
        }
        else
            break;
    }
    return 0;
}