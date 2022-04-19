#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct event
{
    char title[256];
    int time;
    char description[256];
} event;

int read_already = 0;
int loop_continues = 1;
int newly_created_file = 0;
struct event events[24] = {};

// Formats an integer 0-23 to a 12 hour time format
char *format_time(int t, int o)
{
    char *s = malloc(8);
    if (t < 12)
    {
        if (t == 0)
            t = 12;
        if (t < 10 && o == 0)
            sprintf(s, "%d:00  AM", t);
        else
            sprintf(s, "%d:00 AM", t);
    }
    else if ((t == 12 ? t : t - 12) < 10 && o == 0)
        sprintf(s, "%d:00  PM", (t == 12 ? t : t - 12));
    else
        sprintf(s, "%d:00 PM", (t == 12 ? t : t - 12));
    return s;
}

int main()
{
    // Main program while loop to keep it open
    while (loop_continues == 1)
    {
        // Clear at beginning of loop
        system("clear");
        // Make sure the file is still accessible
        if (access("calendar.csv", F_OK) == 0)
        {
            // If we have not yet read the database file
            if (read_already == 0)
            {
                // If this database is not newly created
                if (newly_created_file == 0)
                {
                    // Since a file existed prior to starting the program, read the events in the file into the events variable
                    FILE *fp;
                    char *line = NULL;
                    size_t len = 0;
                    ssize_t read;
                    char *pt;

                    // Initalize empty linked list with time as -1 so we know if that event is populated or not easily
                    int i;
                    for (i = 0; i < sizeof events / 512; i++)
                    {
                        events[i].time = -1;
                    }

                    // Open calendar.csv and read line by line
                    fp = fopen("calendar.csv", "r");
                    while ((read = getline(&line, &len, fp)) != -1)
                    {
                        // Seperate by comma as it is a csv file
                        pt = strtok(line, ",");
                        int var_type = 0;
                        struct event this_event;
                        while (pt != NULL)
                        {
                            // var_type keeps track of which type of input is currently being processed
                            switch (var_type)
                            {
                            case 0:
                                // Converts pt to an int and copies it to this_event.time
                                this_event.time = atoi(pt);
                                break;
                            case 1:
                                // Copies pt to this_event.title
                                strcpy(this_event.title, pt);
                                break;
                            case 2:
                                // Copies pt to this_event.description, but does not copy the \n
                                strcpy(this_event.description, strtok(pt, "\n"));
                                break;
                            }
                            // Seperate by comma as it is a csv file
                            pt = strtok(NULL, ",");
                            var_type++;
                        }
                        // Add this_event to the events array
                        events[this_event.time] = this_event;
                    }
                    fclose(fp);
                }
                else
                {
                    // Initalize empty linked list with time as -1 so we know if that event is populated or not easily
                    int i;
                    for (i = 0; i < sizeof events / 512; i++)
                    {
                        events[i].time = -1;
                    }
                }
                read_already = 1;
            }
            // MAIN PROGRAM LOOP
            printf("Enter a command ([P]rint/[I]nsert/[D]elete/[T]ime Availability/[S]ave/[Q]uit): ");
            char input;
        begin_loop:
            while ((input = getchar()) != '\n')
            {
                switch (input)
                {
                case 'P':;
                case 'p':;
                    // Print events
                    int i;
                    // For each event
                    for (i = 0; i < (sizeof events / 512); i++)
                    {
                        // If event is not initialized
                        if (events[i].time != -1)
                            // Print event
                            printf("[%s] %s : %s", format_time(events[i].time, 0), events[i].title, events[i].description);
                        else
                            // Print empty time slot
                            printf("[%s] -----", format_time(i, 0));
                        // Print newline either way
                        printf("\n");
                    }
                    break;
                case 'I':;
                case 'i':;
                    // Insert event
                    struct event insert_event;
                    // Enter title
                    printf("Enter a title: ");
                    scanf(" %[^\n]s", insert_event.title);
                    // Enter description
                    printf("Enter a description: ");
                    scanf(" %[^\n]s", insert_event.description);
                    // Enter time
                    printf("Enter a time (as an integer, 0-23): ");
                    scanf("%d", &insert_event.time);
                    // Insert event
                    events[insert_event.time] = insert_event;
                    printf("Event has been inserted successfully.\n");
                    break;
                case 'D':;
                case 'd':;
                    // Delete event by time
                    int del_time;
                    // Input a time
                    printf("Input the integer (0-23) of the event you wish to delete: ");
                    scanf("%d", &del_time);
                    // If time slot does not have event
                    if (events[del_time].time == -1)
                        printf("There is no calendar event from %s to %s. Nothing has been deleted.\n", format_time(del_time, 1), format_time(del_time + 1, 1));
                    else
                    {
                        // If time slot has event
                        printf("Event successfully deleted [%s]: %s\n", format_time(del_time, 1), events[del_time].title);
                        // Set time to -1 to show no event
                        events[del_time].time = -1;
                    }
                    break;
                case 'T':;
                case 't':;
                    // Query time for availability
                    // Display menu, fake a getchar() and just go to beginning of loop, it will deal with the input there
                    printf("Query by Ti[m]e or Tit[l]e: ");
                    getchar();
                    goto begin_loop;
                    break;
                case 'M':;
                case 'm':;
                    // Query by time
                    int time_query;
                    // Enter time
                    printf("Input the integer (0-23) of the hour you wish to query: ");
                    scanf("%d", &time_query);
                    // If time is not found
                    if (events[time_query].time == -1)
                        // Print no event found
                        printf("There is no calendar event from %s to %s.\n", format_time(time_query, 1), format_time(time_query + 1, 1));
                    else
                        // Print found event
                        printf("You already have an event at %s: %s\n", format_time(time_query, 1), events[time_query].title);
                    break;
                case 'L':;
                case 'l':;
                    // Query by title
                    char title_query[256];
                    // Enter title
                    printf("Enter a search query string: ");
                    scanf(" %[^\n]s", title_query);
                    int q_i;
                    int found_any = 0;
                    // For each event
                    for (q_i = 0; q_i < (sizeof events / 512); q_i++)
                    {
                        // If search query is substring of title
                        if (strstr(events[q_i].title, title_query) != NULL)
                        {
                            // Set that we found at least one event
                            found_any = 1;
                            // Print that an event was found
                            printf("Found event at %s: %s\n", format_time(events[q_i].time, 1), events[q_i].title);
                        }
                    }
                    // If we did not find at least one event
                    if (found_any == 0)
                    {
                        printf("There was no calendar event found by the title: %s\n", title_query);
                    }
                    break;
                case 'S':;
                case 's':;
                    // Save the file
                    int s_i;
                    FILE *fp;
                    fp = fopen("calendar.csv", "w+");
                    // For each event
                    for (s_i = 0; s_i < (sizeof events / 512); s_i++)
                    {
                        // If event is initialized
                        if (events[s_i].time != -1)
                        {
                            // Print it to file in CSV format
                            fprintf(fp, "%d,%s,%s\n", events[s_i].time, events[s_i].title, events[s_i].description);
                        }
                    }
                    fclose(fp);
                    break;
                case 'Q':;
                case 'q':;
                    // Exit program
                    loop_continues = 0;
                    break;
                }
            }
        }
        else
        {
            // Create calendar.csv if it does not exist
            printf("Calendar data file does not exist, create it? (Y/N): ");
            char input = getchar();
            if (input == 'y' || input == 'Y')
            {
                // Just create the file and close it
                FILE *fp;
                fp = fopen("calendar.csv", "w");
                fclose(fp);
                printf("File created.\n");
                // Set as 1 so we can skip reading this file as it is obviously empty
                newly_created_file = 1;
                continue;
            }
            else
            {
                // User said not to create file, exit
                printf("Unable to initialize file\n");
                break;
            }
        }
        // Only continue once the user has pressed enter, that way they have time to look at the output
        if (loop_continues == 1)
        {
            printf("Press [Enter] to continue...");
            char cont_input;
            // Just wait for enter and continue
            while ((cont_input = getchar()) != '\n')
            {
            }
        }
    }
    // If loop has stoppped, exit program
    printf("Exiting...\n");
    return 0;
}