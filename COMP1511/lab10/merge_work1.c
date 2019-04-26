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
void write_sightings_file(char filename[], struct pod *first_pod);
void write_sighting(FILE *f, struct pod *p);
void write_date(FILE *f, struct date *d);
void free_sightings(struct pod *p);

void merge_day_whales(struct pod *first_pod);
int check_if_it_is_new(struct pod *this_time, struct pod *existing_day_and_species);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <old_file> <new_file>\n", argv[0]);
        return 1;
    }

    struct pod *first_pod = read_sightings_file(argv[1]);

    merge_day_whales(first_pod);

    write_sightings_file(argv[2], first_pod);

    free_sightings(first_pod);

    return 0;
}


// merge sightings of the same species on the same day
// into the first sighting of the  species on that day
// The number of whales seen in subsequent sightings is added
// to the number of whales seen in the first sighting.
// The subsequent sightings are deleted from the list
// and all associated memory freed.

void merge_day_whales(struct pod *first_pod) {
    // Make a linked-list to store the existing days and species
    struct pod *day_and_species = NULL;
    
    // Let the first pod be the contents of the first list of existing days and species
    day_and_species->when->day = first_pod->when->day;
    day_and_species->when->month = first_pod->when->month;
    day_and_species->when->year = first_pod->when->year;
    day_and_species->how_many = first_pod->how_many;
    strcpy(day_and_species->species, first_pod->species);
    
    // Make the next list of the existing days and species
    struct pod *new_d_and_s = NULL;
    day_and_species->next = new_d_and_s;
    
    // Mark the start point of the existing days and species
    struct pod *start_of_day_and_species1 = day_and_species;
    struct pod *start_of_day_and_species2 = day_and_species;
    
    // Go to next lists
    day_and_species = day_and_species->next;
    first_pod = first_pod->next;
    
    // This loop will store all the new days and species into day_and_species
    while (first_pod != NULL) {
        if (check_if_it_is_new(first_pod, start_of_day_and_species1) == 0) {
            day_and_species->when->day = first_pod->when->day;
            day_and_species->when->month = first_pod->when->month;
            day_and_species->when->year = first_pod->when->year;
            day_and_species->how_many = first_pod->how_many;
            strcpy(day_and_species->species, first_pod->species);
            
            struct pod *new_d_and_s = NULL;
            day_and_species->next = new_d_and_s;
            day_and_species = day_and_species->next;
        }
        first_pod = first_pod->next;
    }
    
    // This loop will sum the amounts of same species on the same day, and print it out
    while (start_of_day_and_species2 != NULL) {
        int whale_count = 0;
        while (first_pod != NULL) {
            int result = strcmp(start_of_day_and_species2->species, first_pod->species);
            if (result == 0 && 
                start_of_day_and_species2->when->day == first_pod->when->day && start_of_day_and_species2->when->month == first_pod->when->month && start_of_day_and_species2->when->year == first_pod->when->year) {
                whale_count = whale_count + first_pod->how_many;
            }
            first_pod = first_pod->next;
        }
        printf("%02d/%02d/%02d ", start_of_day_and_species2->when->day, start_of_day_and_species2->when->month, start_of_day_and_species2->when->year);
        printf("%2d ", whale_count);
        printf("%s\n", start_of_day_and_species2->species);
        start_of_day_and_species2 = start_of_day_and_species2->next;
    }
    
}

/* The function below will check if the new input is 
1) a new species 
2) on a new day
If 1), 2) both true, return 0, else return 1.*/

int check_if_it_is_new(struct pod *this_time, struct pod *existing_day_and_species) {
    int result = 0;
    while (existing_day_and_species != NULL) {
        int a = strcmp(existing_day_and_species->species, this_time->species);
        if (a == 0) {
            result = 1;
        }
        if (existing_day_and_species->when->day == this_time->when->day) {
            result = 1;
        }
        if (existing_day_and_species->when->month == this_time->when->month) {
            result = 1;
        }
        if (existing_day_and_species->when->year == this_time->when->year) {
            result = 1;
        }
        existing_day_and_species = existing_day_and_species->next;
    }

    return result;
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


// print linked list of sightings to stream filename

void write_sightings_file(char filename[], struct pod *first_pod) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        fprintf(stderr,"error: file '%s' can not open\n", filename);
        exit(1);
    }

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

// free the list of sightings

void free_sightings(struct pod *p) {
    struct pod *curr = p;
    while (curr != NULL) {
        struct pod *next = curr->next;
        free(curr->species);
        free(curr->when);
        free(curr);
        curr = next;
    }
}
