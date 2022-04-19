#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct event
{
    char title[256];
    int time;
    char description[256];
    struct event *next;
} event_t;

int read_already = 0;
int loop_continues = 1;
int newly_created_file = 0;

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

// Append to list
void *append(event_t *head, int time, char title[256], char description[256])
{
    // Go to the last event
    event_t *cursor = head;
    while (cursor->next != NULL)
        cursor = cursor->next;

    // Create an event
    cursor->next = (event_t *)malloc(sizeof(event_t));
    // Set next as NULL
    cursor->next->next = NULL;
    // Set time, title and description
    cursor->next->time = time;
    strcpy(cursor->next->title, title);
    strcpy(cursor->next->description, description);
}

// Sort event list
void *sort_events(event_t *head)
{
    // Create a cursor and two selectors so that they can be swapped
    event_t *cursor, *selector1, *selector2;

    // Set cursor to beginning of list
    cursor = head;
    // Set head to NULL temporarily while the list is sorted
    head = NULL;

    // Loop through entire list
    while (cursor != NULL)
    {
        // Set selector2 to cursor
        selector2 = cursor;
        // Move cursor forward by 1
        cursor = cursor->next;
        // If head has been set (at least one loop has occured)
        if (head != NULL)
        {
            // If the selector time is greater than the current head time
            if (selector2->time > head->time)
            {
                // Set selector1 as head
                selector1 = head;
                // While there are events after head AND selector2's time is greater than the event after selector1's time
                while ((selector1->next != NULL) && (selector2->time > selector1->next->time))
                {
                    // Set the selector as the next, keep the loop going
                    selector1 = selector1->next;
                }
                // Switch the selectors to swap order
                selector2->next = selector1->next;
                selector1->next = selector2;
            }
            else
            {
                // Make head after selector
                selector2->next = head;
                // Set selector as new head
                head = selector2;
            }
        }
        else
        {
            // Set the head->next to NULL on the first run
            selector2->next = NULL;
            // Set the new head
            head = selector2;
        }
    }
}

// Search for an event by time
event_t *search_time(event_t *head, int time)
{
    event_t *cursor = head;
    // Loop through whole list
    while (cursor != NULL)
    {
        // If time equals event time
        if (cursor->time == time)
            // Return event if found
            return cursor;
        // Go to next event
        cursor = cursor->next;
    }
    // Looped through all, event not found, return NULL
    return NULL;
}

// Search for an event by title
event_t *search_title(event_t *head, char title[256])
{
    event_t *cursor = head;
    // Loop through whole list
    while (cursor != NULL)
    {
        // If title is a substring of cursor->title
        if (strstr(cursor->title, title) != NULL)
            // Return found event
            return cursor;
        // Go to next event
        cursor = cursor->next;
    }
    // Looped through all, event not found, return NULL
    return NULL;
}

// Delete an event
event_t *remove_any(event_t *head, event_t *del_event)
{
    // If del_event is the head
    if (del_event == head)
    {
        // If empty list/head
        if (head == NULL)
            return NULL;
        event_t *front = head;
        // Set head to the next possible event
        head = head->next;
        front->next = NULL;
        // If last event
        if (front == head)
            head = NULL;
        // Free front event from memory
        free(front);
        // Return new head
        return head;
    }

    // If del_event is the last event
    if (del_event->next == NULL)
    {
        // If head/list is empty
        if (head == NULL)
            return NULL;

        // Set cursor to head
        event_t *cursor = head;
        event_t *back = NULL;
        // Loop through list
        while (cursor->next != NULL)
        {
            // Set each event back
            back = cursor;
            cursor = cursor->next;
        }
        // If back of list is not NULL, set next event to NULL to denote end of list
        if (back != NULL)
            back->next = NULL;

        // If it is last event in list
        if (cursor == head)
            head = NULL;
        // Free cursor from memory
        free(cursor);
        // Return existsing head
        return head;
    }

    // If event is not front or back of list
    event_t *cursor = head;
    // Loop through list
    while (cursor != NULL)
    {
        // If cursor is at event we are deleting
        if (cursor->next = del_event)
            break;
        // Move cursor to next event
        cursor = cursor->next;
    }

    // If cursor is found
    if (cursor != NULL)
    {
        // Create tmp event equal to next event
        event_t *tmp = cursor->next;
        // Set cusor next to tmp next
        cursor->next = tmp->next;
        // Set tmp next to NULL after set
        tmp->next = NULL;
        // Free tmp from memory
        free(tmp);
    }
    return head;
}

// Main Method
int main()
{
    // Initiate the linked list
    event_t *head = NULL;
    head = (event_t *)malloc(sizeof(event_t));

    head->time = -1;
    head->next = NULL;

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

                    // Open calendar.csv and read line by line
                    fp = fopen("calendar.csv", "r");
                    while ((read = getline(&line, &len, fp)) != -1)
                    {
                        // Seperate by comma as it is a csv file
                        pt = strtok(line, ",");
                        // 0 = time, 1 = tile, 2 = description while reading from file between commas
                        int var_type = 0;

                        // Set current to head
                        event_t *current = head;
                        // Loop through events
                        while (current->next != NULL)
                        {
                            // Set current to once more, loop until the end of the list
                            current = current->next;
                        }
                        // Create new event at current next
                        current->next = (event_t *)malloc(sizeof(event_t));
                        // Set the next of the new event as NULL to denote end of list
                        current->next->next = NULL;
                        // While reading between commas
                        while (pt != NULL)
                        {
                            // var_type keeps track of which type of input is currently being processed
                            switch (var_type)
                            {
                            case 0:
                                // Converts pt to an int and copies it to current->next->time
                                current->next->time = atoi(pt);
                                break;
                            case 1:
                                // Copies pt to current->next->title
                                strcpy(current->next->title, pt);
                                break;
                            case 2:
                                // Copies pt to current->next->description, but does not copy the \n
                                strcpy(current->next->description, strtok(pt, "\n"));
                                break;
                            }
                            // Seperate by comma as it is a csv file
                            pt = strtok(NULL, ",");
                            // Bump var_type
                            var_type++;
                        }
                    }
                    // Close file
                    fclose(fp);
                }
                // Mark that file as been read
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
                    event_t *cursor = head;
                    while (cursor != NULL)
                    {
                        if (cursor->time != -1)
                            // Print event
                            printf("[%s] %s : %s\n", format_time(cursor->time, 0), cursor->title, cursor->description);
                        cursor = cursor->next;
                    }
                    break;
                case 'I':;
                case 'i':;
                    // Insert event
                    int time;
                    char title[256], description[256];
                    // Enter title
                    printf("Enter a title: ");
                    scanf(" %[^\n]s", &title);
                    // Enter description
                    printf("Enter a description: ");
                    scanf(" %[^\n]s", &description);
                    // Enter time
                    printf("Enter a time (as an integer, 0-23): ");
                    scanf("%d", &time);
                    // Insert event
                    if (search_time(head, time) == NULL)
                    {
                        append(head, time, title, description);
                        printf("Event has been inserted successfully.\n");
                        sort_events(head);
                    }
                    else
                        printf("Unable to insert new event: A different event already exists at %s\n", format_time(time, 1));
                    break;
                case 'D':;
                case 'd':;
                    // Delete event by time
                    int del_time;
                    // Input a time
                    printf("Input the integer (0-23) of the event you wish to delete: ");
                    scanf("%d", &del_time);
                    event_t *searched_event = search_time(head, del_time);
                    if (searched_event != NULL)
                    {
                        printf("Event successfully deleted [%s]: %s\n", format_time(del_time, 1), searched_event->title);
                        remove_any(head, searched_event);
                    }
                    else
                        printf("There is no calendar event from %s to %s. Nothing has been deleted.\n", format_time(del_time, 1), format_time(del_time + 1, 1));
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
                    // Search for time
                    event_t *queried_time_event = search_time(head, time_query);
                    if (queried_time_event != NULL)
                        // Print found event
                        printf("You already have an event at %s: %s\n", format_time(time_query, 1), queried_time_event->title);
                    else
                        // Print no event found
                        printf("There is no calendar event from %s to %s.\n", format_time(time_query, 1), format_time(time_query + 1, 1));
                    break;
                case 'L':;
                case 'l':;
                    // Query by title
                    char title_query[256];
                    // Enter title
                    printf("Enter a search query string: ");
                    scanf(" %[^\n]s", title_query);
                    // Search for title
                    event_t *queried_title_event = search_title(head, title_query);
                    if (queried_title_event != NULL)
                        // Print found event
                        printf("Event found by title \"%s\" at %s\n", queried_title_event->title, format_time(queried_title_event->time, 1));
                    else
                        // Print no event found
                        printf("There is no calendar event with title %s.\n", title_query);
                    break;
                case 'S':;
                case 's':;
                    // Save the file
                    int s_i;
                    FILE *fp;
                    fp = fopen("calendar.csv", "w+");
                    // Sort the list just to be sure before we save
                    sort_events(head);
                    // For each event
                    event_t *save_cursor = head;
                    while (save_cursor != NULL)
                    {
                        if (save_cursor->time != -1)
                            // Print event
                            fprintf(fp, "%d,%s,%s\n", save_cursor->time, save_cursor->title, save_cursor->description);
                        save_cursor = save_cursor->next;
                    }
                    fclose(fp);
                    printf("Calendar saved successfully.\n");
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
                // Purposely nothing
            }
        }
    }
    // If loop has stoppped, exit program
    printf("Exiting...\n");
    return 0;
}