#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SPECIES_NAME_LENGTH 4096

// a struct to represent the date
// a whale pod sighting was made

struct date {
    int year;
    int month;
    int day;
};

// a struct to represent a sighting
// of a pod (group) of whales

struct pod {
    struct pod  *next;
    struct date *when;
    int         how_many;
    char        *species;
};


struct pod *read_sightings_file(char filename[]);
struct pod *read_sighting(FILE *f);
struct date *read_date(FILE *f);
void write_sightings(FILE *f, struct pod *first_pod);
void write_sighting(FILE *f, struct pod *p);
void write_date(FILE *f, struct date *d);

struct pod *order_whales(struct pod *first_pod);
struct pod *numer_sort(struct pod *first_pod);
struct pod *alpha_sort(struct pod *first_pod);
struct pod *chrono_sort(struct pod *first_pod);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    struct pod *first_pod = read_sightings_file(argv[1]);

    struct pod *new_first_pod = order_whales(first_pod);
    write_sightings(stdout, new_first_pod);

    return 0;
}


// return whale list rearranged into increasing (non-decreasing) order

struct pod *order_whales(struct pod *first_pod) {
    // if we reverse the order of 3 kinds of sortings,
    // we can get chronologically then alphabetically 
    // then numerically at the end  
    
    // firstly, sort numerically on number of whales
    first_pod = numer_sort(first_pod);
    
    // secondly, sort alphabetically on species
    first_pod = alpha_sort(first_pod);
    
    // finally, sort chronologically on date
    first_pod = chrono_sort(first_pod);
    
    return first_pod;
}



































// SORT FUNCTIONS
struct pod *numer_sort(struct pod *first_pod) {
    struct pod *head = first_pod;
    struct pod *curr;
    struct pod *prev;
    struct pod *after;
    
    // length of the list
    // bubble sort
    int swap = 1;
    int time = 0;
    int flag;
    while (swap) {
        curr = head;
        swap = 0;
        flag = 0;
        // comparing the 1st and 2nd elements, so don't have "prev"
        if (curr->how_many > curr->next->how_many) {
            // swap
            after = curr->next;
            curr->next = after->next;
            after->next = curr;
            prev = after;
            // mark the swap
            head = after;
            swap = 1;
            flag = 1;
        }
        if (flag == 0) {
            prev = curr;
            curr = curr->next;
            
        }
        // also need to consider "prev"
        while (curr->next != NULL) {
            flag = 0;
            if (curr->how_many > curr->next->how_many) {
                // swap
                after = curr->next;
                curr->next = after->next;
                after->next = curr;
                prev->next = after;
                // mark the swap
                swap = 1;
                flag = 1;
            }
            if (flag == 0) {
                prev = prev->next;
                curr = curr->next;
            }
            if (flag == 1) {
                prev = after;
            }
        }
    } 
    
    return head;
}
    
struct pod *alpha_sort(struct pod *first_pod) {
    struct pod *head = first_pod;
    struct pod *curr;
    struct pod *prev;
    struct pod *after;
    
    // length of the list
    // bubble sort
    int swap = 1;
    int time = 0;
    int flag;
    while (swap) {
        curr = head;
        swap = 0;
        flag = 0;
        // comparing the 1st and 2nd elements, so don't have "prev"
        if (strcmp(curr->species, curr->next->species) > 0) {
            // swap
            after = curr->next;
            curr->next = after->next;
            after->next = curr;
            prev = after;
            // mark the swap
            head = after;
            swap = 1;
            flag = 1;
        }
        if (flag == 0) {
            prev = curr;
            curr = curr->next;
            
        }
        // also need to consider "prev"
        while (curr->next != NULL) {
            flag = 0;
            if (strcmp(curr->species, curr->next->species) > 0) {
                // swap
                after = curr->next;
                curr->next = after->next;
                after->next = curr;
                prev->next = after;
                // mark the swap
                swap = 1;
                flag = 1;
            }
            if (flag == 0) {
                prev = prev->next;
                curr = curr->next;
            }
            if (flag == 1) {
                prev = after;
            }
        }
    } 
    
    return head;
}

struct pod *chrono_sort(struct pod *first_pod) {
    struct pod *head = first_pod;
    struct pod *curr;
    struct pod *prev;
    struct pod *after;
    
    int curr_date;
    int curr_next_date;
    
    // length of the list
    // bubble sort
    int swap = 1;
    int time = 0;
    int flag;
    while (swap) {
        curr = head;
        swap = 0;
        flag = 0;
        // comparing the 1st and 2nd elements, so don't have "prev"
        curr_date = 10000 * curr->when->year + 100 * curr->when->month + curr->when->day;
        curr_next_date = 10000 * curr->next->when->year + 100 * curr->next->when->month + curr->next->when->day;
        if (curr_date > curr_next_date) {
            // swap
            after = curr->next;
            curr->next = after->next;
            after->next = curr;
            prev = after;
            // mark the swap
            head = after;
            swap = 1;
            flag = 1;
        }
        if (flag == 0) {
            prev = curr;
            curr = curr->next;
            
        }
        // also need to consider "prev"
        while (curr->next != NULL) {
            flag = 0;
            curr_date = 10000 * curr->when->year + 100 * curr->when->month + curr->when->day;
            curr_next_date = 10000 * curr->next->when->year + 100 * curr->next->when->month + curr->next->when->day;
            if (curr_date > curr_next_date) {
                // swap
                after = curr->next;
                curr->next = after->next;
                after->next = curr;
                prev->next = after;
                // mark the swap
                swap = 1;
                flag = 1;
            }
            if (flag == 0) {
                prev = prev->next;
                curr = curr->next;
            }
            if (flag == 1) {
                prev = after;
            }
        }
    } 
    
    return head;


    
}























//
// DO NOT CHANGE THE FUNCTIONS BELOW HERE
//

// return linked list of sightings read from filename
// exit called if there is an error

struct pod *read_sightings_file(char filename[]) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr,"error: file '%s' can not open\n", filename);
        exit(1);
    }

    struct pod *first_sighting = NULL;
    struct pod *last_sighting = NULL;

    struct pod *sighting = read_sighting(f);
    while (sighting != NULL) {
        if (first_sighting == NULL) {
            first_sighting = sighting;
            first_sighting->next = NULL;
        } else {
            last_sighting->next = sighting;
        }
        last_sighting = sighting;
        sighting = read_sighting(f);
    }

    return first_sighting;
}


// read a whale sighting (date, number of whales, whale species)
// return a pointer to a malloced struct containing thes edetails
// return NULL if a sighting can not be read

struct pod *read_sighting(FILE *f) {
    struct pod *p = malloc(sizeof (struct pod));
    if (p == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }

    p->next = NULL;

    p->when = read_date(f);
    if (p->when == NULL) {
        free(p);
        return NULL;
    }

    int n_scanned = fscanf(f, "%d", &(p->how_many));
    if (n_scanned != 1) {
        free(p);
        return NULL;
    }

    fgetc(f);
    char species_buffer[MAX_SPECIES_NAME_LENGTH];
    if (fgets(species_buffer, MAX_SPECIES_NAME_LENGTH, f) == NULL) {
        free(p);
        return NULL;
    }
   // finish string at '\n' if there is one
    char *newline_ptr = strchr(species_buffer, '\n');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }

    // also finish string at '\r' if there is one - files from Windows  will
    newline_ptr = strchr(species_buffer, '\r');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }

    // malloc a chararray long enough to hold species name
    // and copy species to it
    p->species = malloc(strlen(species_buffer) + 1);
    if (p->species == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    strcpy(p->species, species_buffer);

    return p;
}


// read a date in day/month/year format from stream f
// return a pointer to a malloced date struct containing them
//  return NULL if a date can not be read

struct date *read_date(FILE *f) {
    struct date *d = malloc(sizeof (struct date));
    if (d == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    int n_scanned = fscanf(f, "%d/%d/%d", &(d->day), &(d->month), &(d->year));
    if (n_scanned != 3) {
        free(d);
        return NULL;
    }
    return d;
}


// print linked list of sightings to stream f

void write_sightings(FILE *f, struct pod *first_pod) {
    struct pod *p = first_pod;
    while (p != NULL) {
        write_sighting(f, p);
        p = p->next;
    }
}


// print pod details to stream f

void write_sighting(FILE *f, struct pod *p) {
    write_date(f, p->when);
    fprintf(f, " %2d %s\n", p->how_many, p->species);
}


// print date to  stream f

void write_date(FILE *f, struct date *d) {
    fprintf(f, "%02d/%02d/%02d", d->day, d->month, d->year);
}
