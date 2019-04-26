void merge_day_whales(struct pod *first_pod) {
    if (first_pod == NULL) {
        return;
    }
    struct pod *curr = first_pod->next;
    struct pod *prev = first_pod;
    // The loop merge same day and species records
    while (curr != NULL) {
        struct pod *existing = first_pod;
        int index = 0;
        while (existing != curr) {
            if (same_day_and_species(curr, existing) == 1) {
                // Sum the number of same species at same day
                existing->how_many = existing->how_many + curr->how_many;
                // delete curr
                prev->next = curr->next;
                // free curr
                struct pod *temp = curr->next;
                free(curr);
                curr = temp;

                index = 1;
            }
            existing = existing->next;
        }
        if (curr != NULL && index == 0) {
            curr = curr->next;
            prev = prev->next;
        }
    }
    
    // Print out the merged list for debugging
    struct pod *curr1 = first_pod;
    while (curr1 != NULL) {
        printf("%02d/%02d/%02d ", curr1->when->day, curr1->when->month, curr1->when->year);
        printf("%2d ", curr1->how_many);
        printf("%s\n", curr1->species);
        curr1 = curr1->next;
    }
    
}
