/* "work out what the local time is in your town" so when phoning home 
you don't call too early or too late and wake your family */
// Written by XINGJIAN, LI. z5190719.

#include <stdio.h>
#include <assert.h>

// You must use these #defines - DO NOT CHANGE THEM

#define TOWN_ADELAIDE       0
#define TOWN_BRISBANE       1
#define TOWN_BROKEN_HILL    2
#define TOWN_CANBERRA       3
#define TOWN_DARWIN         4
#define TOWN_EUCLA          5
#define TOWN_HOBART         6
#define TOWN_LORD_HOWE_IS   7
#define TOWN_MELBOURNE      8
#define TOWN_PERTH          9
#define TOWN_SYDNEY         10

// New Zealand

#define TOWN_AUCKLAND       11
#define TOWN_CHRISTCHURCH   12
#define TOWN_WELLINGTON     13

// Australia

#define TIMEZONE_AWST_OFFSET  800 // Australian Western Standard Time
#define TIMEZONE_ACWST_OFFSET 845 /* Australian Central Western Standard
Time*/

#define TIMEZONE_ACST_OFFSET  930 // Australian Central Standard Time
#define TIMEZONE_ACDT_OFFSET 1030 // Australian Central Daylight Time

#define TIMEZONE_AEST_OFFSET 1000 // Australian Eastern Standard Time
#define TIMEZONE_AEDT_OFFSET 1100 // Australian Eastern Daylight Time

#define TIMEZONE_LHST_OFFSET 1030 // Lord Howe Standard Time
#define TIMEZONE_LHDT_OFFSET 1100 // Lord Howe Daylight Time

// New Zealand
#define TIMEZONE_NZST_OFFSET 1200 // NZ Standard Time
#define TIMEZONE_NZDT_OFFSET 1300 // NZ Daylight Time

// returned by get_local_time
#define INVALID_INPUT (-1)

// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
int get_local_time(int town, int utc_month, int utc_day, int utc_time);
int check_invalid(int town, int utc_month, int utc_day, int utc_time);
int standard_offset(int town);
int daylight_saving_time_to_standard_time(int town);
int standard_time_to_daylight_saving_time(int town);
int offset(int town);
void run_unit_tests(void);

// DO NOT CHANGE THIS FUNCTION

// This main function won't be marked as part of the assignment
// It tests the functions you have to write.
// Do not change this main function.  If it does not work with
// your functions you have misunderstood the assignment.

int main(void) {
    int call_get_local_time = 0;

    printf("Enter 0 to call run_unit_tests()\n");
    printf("Enter 1 to call get_local_time()\n");
    printf("Call which function: ");
    scanf("%d", &call_get_local_time);

    if (!call_get_local_time) {
        printf("calling run_unit_tests()\n");
        run_unit_tests();
        printf("unit tests done\n");
        return 0;
    }

    int town = 0;
    int month = 0;
    int day = 0;
    int time = 0;

    printf("Enter %d for Adelaide\n", TOWN_ADELAIDE);
    printf("Enter %d for Brisbane\n", TOWN_BRISBANE);
    printf("Enter %d for Broken_hill\n", TOWN_BROKEN_HILL);
    printf("Enter %d for Canberra\n", TOWN_CANBERRA);
    printf("Enter %d for Darwin\n", TOWN_DARWIN);
    printf("Enter %d for Eucla\n", TOWN_EUCLA);
    printf("Enter %d for Hobart\n", TOWN_HOBART);
    printf("Enter %d for Lord Howe Island\n", TOWN_LORD_HOWE_IS);
    printf("Enter %d for Melbourne\n", TOWN_MELBOURNE);
    printf("Enter %d for Perth\n", TOWN_PERTH);
    printf("Enter %d for Sydney\n", TOWN_SYDNEY);
    printf("Enter %d for Auckland\n", TOWN_AUCKLAND);
    printf("Enter %d for Christchurch\n", TOWN_CHRISTCHURCH);
    printf("Enter %d for Wellington\n", TOWN_WELLINGTON);

    printf("Which town: ");
    scanf("%d", &town);

    printf("Enter UTC month as integer 1..12: ");
    scanf("%d", &month);

    printf("Enter UTC day as integer 1..31: ");
    scanf("%d", &day);

    printf("Enter UTC time as hour * 100 + minutes\n");
    printf("Enter UTC time as integer [0..2359]: ");
    scanf("%d", &time);

    int local_time = get_local_time(town, month, day, time);

    if (local_time == INVALID_INPUT) {
        printf("Lixiaodong kouwang invalid input - local time could not be calculated\n");
    } else {
        printf("local_time is %d\n", local_time);
    }
    return 0;
}

// Given an Australian town and a 2018 UTC time
// return the local time in the Australian town

// time is returned as hours*100 + minutes
// INVALID_INPUT is return for invalid inputs

// utc_month should be 1..12
// utc_day should be 1..31
// utc_time should be 0..2359
// utc_time is hours*100 + minutes

// note UTC year is assumed to be 2018
// note UTC seconds is assumed to be zero

int get_local_time(int town, int utc_month, int utc_day, int utc_time) {
    
    // the genuine time difference between local time and UTC time
    int LOCAL_OFFSET = 0;
    
    // the time difference between local time(at standard time) 
    // and UTC time
    int LOCAL_STANDARD_TIME_OFFSET = standard_offset(town);
    
    // to calculate daylight_saving_time_to_standard_time
    int delta_timestamp1 = daylight_saving_time_to_standard_time(town);
    
    // to calculate standard_time_to_daylight_saving_time
    int delta_timestamp2 = standard_time_to_daylight_saving_time(town); 
    
    
    // tramsform UTC time to decimal form
    int utctimestamp = 1000000 * utc_month + 10000 * utc_day + utc_time;
    
    /* get the correct offset for each town, firstly by checking 
       Australian or NZ, then by checking the date is belong to Standard
       time or Daylight Saving Time */
    if (// Australian town
        town == TOWN_SYDNEY || 
        town == TOWN_ADELAIDE || 
        town == TOWN_BRISBANE || 
        town == TOWN_PERTH || 
        town == TOWN_CANBERRA ||
        town == TOWN_DARWIN || 
        town == TOWN_HOBART ||
        town == TOWN_MELBOURNE || 
        town == TOWN_EUCLA || 
        town == TOWN_BROKEN_HILL || 
        town ==  TOWN_LORD_HOWE_IS) {
        if (// Standard Time 
            (utctimestamp + 
            delta_timestamp1 + 
            LOCAL_STANDARD_TIME_OFFSET)
            >= 4010200 && 
            (utctimestamp + 
            delta_timestamp2 + 
            LOCAL_STANDARD_TIME_OFFSET) 
            < 10070200) {
            LOCAL_OFFSET = LOCAL_STANDARD_TIME_OFFSET;
        } else {// Daylight Saving Time
            LOCAL_OFFSET = offset(town);
        }    
    } else if (// NEW ZEALAND town
               town == TOWN_WELLINGTON || 
               town == TOWN_AUCKLAND || 
               town == TOWN_CHRISTCHURCH) {
        if (// Standard Time 
            (utctimestamp + 
            delta_timestamp1 +
            LOCAL_STANDARD_TIME_OFFSET) 
            >= 4010200 &&
            (utctimestamp + 
            delta_timestamp2 +
            LOCAL_STANDARD_TIME_OFFSET) 
            < 9300200) {
            LOCAL_OFFSET = LOCAL_STANDARD_TIME_OFFSET;
        } else {// Daylight Saving Time
            LOCAL_OFFSET = TIMEZONE_NZDT_OFFSET;
        } 
    }
    
    /* This part looks strange but it is really important, it converts 
        
        decimal system(timestamp) and other system(days in a month).
        
        In the early versions I got 160 which the correct output should 
        
        be 200. This is because of the system, when reaching 60, 
        
        in time system we need to go to next hour, but here 
        
        in the decimal system it is still counting,
        
        and gives 160 rather than 200.*/ 
    if (((utc_time + LOCAL_OFFSET) - ((utc_time + LOCAL_OFFSET) / 100)
        * 100) - 60 >= 0) {
        LOCAL_OFFSET = LOCAL_OFFSET - 60 + 100;
    }
    
/* This part look even more strange but it can solve a big problem.

When I first autotest my work the last output was incorrect.

It looks like this:
        
Test21 (get_local_time(TOWN_EUCLA, 2, 6, 2359))-failed(Incorrect output)
Your program produced these 1 lines of output:
get_local_time(5, 2, 6, 2359) returned 804

The correct 1 lines of output for this test were:
get_local_time(5, 2, 6, 2359) returned 844

The difference between your output(-) and the correct output(+) is:
- get_local_time(5, 2, 6, 2359) returned 804
+ get_local_time(5, 2, 6, 2359) returned 844

The input for this test was:
5 2 6 2359
 
 At first I really got confused, when I input the number by hand 
 
 I realized "2359" plus "845" equals to "3204", it rounded!!!
 
 Fortunately only EUCLA has a time difference which "45" +
 
 "a number < 60" can over 100. So I write this part to correct this bug.
 
 Xingjian, Li.*/
    if (town == TOWN_EUCLA && (utc_time - 
        (utc_time / 100) * 100) >= 55) {
        LOCAL_OFFSET = LOCAL_OFFSET + 40;
    }
    // obtain a valid time in the following day 
    if (utc_time + LOCAL_OFFSET > 2359/* If date change*/) {
        LOCAL_OFFSET = LOCAL_OFFSET - 2400;
    } else {// Date does not change
        LOCAL_OFFSET = LOCAL_OFFSET + 0;
    }
    // make sure that a valid time
    // (ie.0000 to 2359) will be returned.
    int check_result = check_invalid(town, utc_month,  
        utc_day, utc_time);
    if (check_result != -1) {
        return utc_time + LOCAL_OFFSET;
    } else {
        return INVALID_INPUT;
    }
}
// CHANGE THIS FUNCTION
// YOU ARE NOT PERMITTED TO USE ARRAYS, LOOPS, PRINTF OR SCANF
// SEE THE ASSIGNMENT SPECIFICATION FOR MORE RESTRICTIONS

// ADD YOUR FUNCTIONS HERE

// This function checks if the user's input is valid
// If input is valid return 1, otherwise return "INVALID_INPUT" 
// It checks month, date, time and then date in certain months
// For example: February only has 28 days 
int check_invalid(int town, int utc_month, int utc_day, int utc_time) {
    if (town < 0 || town >= 14 || utc_month > 12 || utc_month < 1 ||
        utc_time < 0 || utc_time > 2359) { 
        return INVALID_INPUT;
    } else if ((utc_month == 1 || utc_month == 3 || utc_month == 5 ||
               utc_month == 7 || utc_month == 8 || utc_month == 10 || 
               utc_month == 12) && (utc_day > 31 || utc_day <  1)) {
        return INVALID_INPUT;
    } else if ((utc_month == 4 || utc_month == 6 || utc_month == 9 ||
               utc_month == 11) && (utc_day > 30 ||  utc_day <  1)) {
        return INVALID_INPUT;
    } else if (utc_month == 2 && (utc_day > 28 || utc_day <  1)) {
        return INVALID_INPUT;
    } else {
        return 1;
    }
}
    
// return "offset of standard" refers to "town"    
int standard_offset(int town) {
    if (town == TOWN_ADELAIDE) {
        return TIMEZONE_ACST_OFFSET;
    } else if (town == TOWN_BRISBANE) {
        return TIMEZONE_AEST_OFFSET;
    } else if (town == TOWN_BROKEN_HILL) {
        return TIMEZONE_ACST_OFFSET;
    } else if (town == TOWN_CANBERRA) {
        return TIMEZONE_AEST_OFFSET;
    } else if (town == TOWN_DARWIN) {
        return TIMEZONE_ACST_OFFSET;
    } else if (town == TOWN_EUCLA) {
        return TIMEZONE_ACWST_OFFSET;
    } else if (town == TOWN_HOBART) {
        return TIMEZONE_AEST_OFFSET;
    } else if (town == TOWN_LORD_HOWE_IS) {
        return TIMEZONE_LHST_OFFSET;
    } else if (town == TOWN_MELBOURNE) {
        return TIMEZONE_AEST_OFFSET;
    } else if (town == TOWN_PERTH) {
        return TIMEZONE_AWST_OFFSET;
    } else if (town == TOWN_SYDNEY) {
        return TIMEZONE_AEST_OFFSET;
    } else if (town == TOWN_AUCKLAND) {
        return TIMEZONE_NZST_OFFSET;
    } else if (town == TOWN_CHRISTCHURCH) {
        return TIMEZONE_NZST_OFFSET;
    } else if (town == TOWN_WELLINGTON) {
        return TIMEZONE_NZST_OFFSET;
    } else {
        return -1;
    }
} 

/* "I use the standard and daylight changing timestamp of
 
 standard time(ie. Australia:4010200(02:00(standard time), April 1st) 
 
 and 10070200(02:00(standard time), October 7th) and New Zealand:
 
 4010200(02:00(standard time), April 4th) and 
 
 9300200(02:00()standard time), September 30th ) minus every towns' 
 
 time zone offset and minus the UTC timestamp at that moment to 
 
 calculate the socalled "delta timestamp"(ie: 697640, 697600, 7640 
 
 and 7600 below).
 
 For example, Sydney, Australia, use 4010200 minus 3311600(means 16:00,
 
 March 31st, the UTC time when standard and daylight changing in Sydney)
 
 and minus 1000(TIMEZONE_AEST_OFFSET, Sydney's offset), so then we get 
 
 "TOWN_SYDNEY_DELTA_TIMESTAMP_1" equals to 697600"(Xingjian, Li).*/    
int daylight_saving_time_to_standard_time(int town) {
    if (town == TOWN_ADELAIDE) {
        return 697640;
    } else if (town == TOWN_BRISBANE) {
        return 697600;
    } else if (town == TOWN_BROKEN_HILL) {
        return 697640;
    } else if (town == TOWN_CANBERRA) {
        return 697600;
    } else if (town == TOWN_DARWIN) {
        return 697640;
    } else if (town == TOWN_EUCLA) {
        return 697640;
    } else if (town == TOWN_HOBART) {
        return 697600;
    } else if (town == TOWN_LORD_HOWE_IS) {
        return 697640; 
    } else if (town == TOWN_MELBOURNE) {
        return 697600;
    } else if (town == TOWN_PERTH) {
        return 697600;
    } else if (town == TOWN_SYDNEY) {
        return 697600;
    } else if (town == TOWN_AUCKLAND) {
        return 697600;
    } else if (town == TOWN_CHRISTCHURCH) {
        return 697600;
    } else if (town == TOWN_WELLINGTON) {
        return 697600;
    } else {
        return -1; 
    }
}
    
int standard_time_to_daylight_saving_time(int town) {
    if (town == TOWN_ADELAIDE) {
        return 7640;
    } else if (town == TOWN_BRISBANE) {
        return 7600;
    } else if (town == TOWN_BROKEN_HILL) {
        return 7640;
    } else if (town == TOWN_CANBERRA) {
        return 7600;
    } else if (town == TOWN_DARWIN) {
        return 7640;
    } else if (town == TOWN_EUCLA) {
        return 7640;
    } else if (town == TOWN_HOBART) {
        return 7600;
    } else if (town == TOWN_LORD_HOWE_IS) {
        return 7640;
    } else if (town == TOWN_MELBOURNE) {
        return 7600;
    } else if (town == TOWN_PERTH) {
        return 7600;
    } else if (town == TOWN_SYDNEY) {
        return 7600;
    } else if (town == TOWN_AUCKLAND) {
        return 7600;
    } else if (town == TOWN_CHRISTCHURCH) {
        return 7600;
    } else if (town == TOWN_WELLINGTON) {
        return 7600;  
    } else {
        return -1;
    }
}
    
// return "offset" refers to "town"
int offset(int town) {
    if (town == TOWN_ADELAIDE) {
        return TIMEZONE_ACDT_OFFSET;
    } else if (town == TOWN_BRISBANE) {
        return TIMEZONE_AEST_OFFSET;
    } else if (town == TOWN_BROKEN_HILL) {
        return TIMEZONE_ACDT_OFFSET;
    } else if (town == TOWN_CANBERRA) {
        return TIMEZONE_AEDT_OFFSET;
    } else if (town == TOWN_DARWIN) {
        return TIMEZONE_ACST_OFFSET;
    } else if (town == TOWN_EUCLA) {
        return TIMEZONE_ACWST_OFFSET;
    } else if (town == TOWN_HOBART) {
        return TIMEZONE_AEDT_OFFSET;
    } else if (town == TOWN_LORD_HOWE_IS) {
        return TIMEZONE_LHDT_OFFSET;
    } else if (town == TOWN_MELBOURNE) {
        return TIMEZONE_AEDT_OFFSET;
    } else if (town == TOWN_PERTH) {
        return TIMEZONE_AWST_OFFSET;
    } else if (town == TOWN_SYDNEY) {
        return TIMEZONE_AEDT_OFFSET;
    } else {
        return -1;
    }
}
    
// ADD A COMMENT HERE EXPLAINING YOUR OVERALL TESTING STRATEGY

// Test Strategy
/* Firstly, test the invalid inputs:
   1.town < 0 
   
   2.town > 13 
   
   3.utc_month > 12 
   
   4.utc_month < 1
   
   5.utc_time < 0
   
   6.utc_time > 2359
   
   7.invalid date in january, march, may, july, august, october, 
   december
   
   8.invalid date in april, june, september, november
   
   9.invalid date in february
   
   Secondly, test by town: 
   
   if it is an Australian town, test by the following 5 circumstances:
   
   1.local standard time(ie.UTC plus TIMEZONE_SOMEPLACEST_OFFSET) is 
   before Aus_changing point 1(02:00, April 1st)
   
   2.local standard time is at Aus_changing point 1
   
   3.local standard time is between Aus_changing point 1 and 
   Aus_changing point 2(02:00, October 7th)
   
   4.local standard time is at Aus_changing point 2
   
   5.local standard time is after Aus_changing point 2
   
   else if it is an New Zealand town, test by the following 5 
   circumstances:
   
   1.local standard time(ie.UTC plus TIMEZONE_SOMEPLACEST_OFFSET) 
   is before NZ_changing point 1(02:00, April 1st)
   
   2.local standard time is at NZ_changing point 1
   
   3.local standard time is between NZ_changing point 1 and 
   NZ_changing point 2(02:00, September 30th)
   
   4.local standard time is at NZ_changing point 2
   
   5.local standard time is after NZ_changing point 2
   
   finally for each circumstances above, 
   test following two circumstances:
   
   1.0 <= utc_time + LOCAL_OFFSET <= 2359
   
   2.utc_time + LOCAL_OFFSET > 2359
   
   If the above 9 + 2 * 5 * 14 = 149 tests are all passed, 
   
   we can conclued that the assignment 1 has been done,
   
   otherwise, I'm done.
   
   Written by Xingjian, Li.
*/
/* In the first testing 9 invalid inputs will be tested.
   In this section 9 tests should have been done.

   In the second testing part six towns(Adelaide, Lord Howe Island, 
   Sydney, Perth, Eucla, Auckland) which are from each timezone
   (AC, LH, AE, AW, ACWST, NZ) will be 
   chosen instead of testing all 14 towns.
   
   Also as "utc_time + LOCAL_OFFSET > 2359" is more complicated 
   than "0 <= utc_time + LOCAL_OFFSET <= 2359", I will only test 
   situations with "utc_time + LOCAL_OFFSET > 2359".
   In this section 6 * 5 = 30 tests should have been done.
    
   Now I got 39 tests.
   
   In the debugging process I found Brisbane is special(no DST in AE_T) 
   and need to be tested.
   
   Then I got 39 + 5 = 44 tests which is greater than 40.
*/

// run unit tests for get_local_time
void run_unit_tests(void) {
    // 2 example unit tests

    // UTC midnight on 20th March -> time in Sydney: 11am AEDT
    assert(get_local_time(TOWN_SYDNEY, 3, 20, 0) == 1100);

    // 42 is not a valid month
    assert(get_local_time(TOWN_SYDNEY, 42, 0, 0) == INVALID_INPUT);

    // ADD YOUR ASSERT STATEMENTS HERE
    
    // -1 is not a valid town
    assert(get_local_time(-1, 3, 20, 0) == INVALID_INPUT);
    
    // 14 is not a valid town
    assert(get_local_time(14, 3, 20, 0) == INVALID_INPUT);
    
    // 13 is not a valid month
    assert(get_local_time(TOWN_SYDNEY, 13, 20, 0) == INVALID_INPUT);
    
    // 0 is not a valid month
    assert(get_local_time(TOWN_SYDNEY, 0, 20, 0) == INVALID_INPUT);
    
    // -1 is not a valid utc_time
    assert(get_local_time(TOWN_SYDNEY, 3, 20, -1) == INVALID_INPUT);
    
    // 2400 is not a valid utc_time
    assert(get_local_time(TOWN_SYDNEY, 3, 20, 2400) == INVALID_INPUT);
    
    // 32 is not a valid month in january
    assert(get_local_time(TOWN_SYDNEY, 1, 32, 0) == INVALID_INPUT);
    
    // 31 is not a valid month in april
    assert(get_local_time(TOWN_SYDNEY, 4, 31, 0) == INVALID_INPUT);
    
    // 29 is not a valid month in february
    assert(get_local_time(TOWN_SYDNEY, 2, 29, 0) == INVALID_INPUT);
    
    // This part will test 5 time on either ST or DST in Adelaide.
    // For example: UTC 16:29 on 31th March  
    // -> time in ADELAIDE: 2:59 ACDT
    assert(get_local_time(TOWN_ADELAIDE, 3, 31, 1629) == 259);
    assert(get_local_time(TOWN_ADELAIDE, 3, 31, 1630) == 200);
    assert(get_local_time(TOWN_ADELAIDE, 3, 31, 1631) == 201);
    assert(get_local_time(TOWN_ADELAIDE, 10, 6, 1630) == 300);
    assert(get_local_time(TOWN_ADELAIDE, 10, 6, 1631) == 301);
    
    // This part will test 5 time on either 
    // ST or DST in Lord Howe Island.
    // For example: UTC 15:29 on 31th March  
    // -> time in Lord Howe Island: 2:29 LHDT
    assert(get_local_time(TOWN_LORD_HOWE_IS, 3, 31, 1529) == 229);
    assert(get_local_time(TOWN_LORD_HOWE_IS, 3, 31, 1530) == 200);
    assert(get_local_time(TOWN_LORD_HOWE_IS, 3, 31, 1531) == 201);
    assert(get_local_time(TOWN_LORD_HOWE_IS, 10, 6, 1530) == 230);
    assert(get_local_time(TOWN_LORD_HOWE_IS, 10, 6, 1531) == 231);
    
    // This part will test 5 time on either ST or DST in Sydney.
    // For example: UTC 15:59 on 31th March 
    // -> time in Sydney: 2:59 AEDT
    assert(get_local_time(TOWN_SYDNEY, 3, 31, 1559) == 259);
    assert(get_local_time(TOWN_SYDNEY, 3, 31, 1600) == 200);
    assert(get_local_time(TOWN_SYDNEY, 3, 31, 1601) == 201);
    assert(get_local_time(TOWN_SYDNEY, 10, 6, 1600) == 300);
    assert(get_local_time(TOWN_SYDNEY, 10, 6, 1601) == 301);
    
    // This part will test 5 time on either ST or DST in Perth.
    // For example: UTC 17:59 on 31th March 
    // -> time in Perth: 1:59 AWDT
    assert(get_local_time(TOWN_PERTH, 3, 31, 1759) == 159);
    assert(get_local_time(TOWN_PERTH, 3, 31, 1800) == 200);
    assert(get_local_time(TOWN_PERTH, 3, 31, 1801) == 201);
    assert(get_local_time(TOWN_PERTH, 3, 31, 1800) == 200);
    assert(get_local_time(TOWN_PERTH, 3, 31, 1801) == 201);
    
    // This part will test 5 time on either ST or DST in Eucla.
    // For example: UTC 17:14 on 31th March 
    // -> time in Perth: 1:59 ACWST
    assert(get_local_time(TOWN_EUCLA, 3, 31, 1714) == 159);
    assert(get_local_time(TOWN_EUCLA, 3, 31, 1715) == 200);
    assert(get_local_time(TOWN_EUCLA, 3, 31, 1716) == 201);
    assert(get_local_time(TOWN_EUCLA, 3, 31, 1715) == 200);
    assert(get_local_time(TOWN_EUCLA, 3, 31, 1716) == 201);
    
    // This part will test 5 time on either ST or DST in Auckland.
    // For example: UTC 13:59 on 31th March  
    // -> time in Auckland: 2:59 NZDT
    assert(get_local_time(TOWN_AUCKLAND, 3, 31, 1359) == 259);
    assert(get_local_time(TOWN_AUCKLAND, 3, 31, 1400) == 200);
    assert(get_local_time(TOWN_AUCKLAND, 3, 31, 1401) == 201);
    assert(get_local_time(TOWN_AUCKLAND, 9, 29, 1400) == 300);
    assert(get_local_time(TOWN_AUCKLAND, 9, 29, 1401) == 301);
    
    // This part will test 5 time on either ST or DST in Brisbane.
    // For example: UTC 15:59 on 31th March 
    // -> time in Perth: 1:59 AEST
    assert(get_local_time(TOWN_BRISBANE, 3, 31, 1559) == 159);
    assert(get_local_time(TOWN_BRISBANE, 3, 31, 1600) == 200);
    assert(get_local_time(TOWN_BRISBANE, 3, 31, 1601) == 201);
    assert(get_local_time(TOWN_BRISBANE, 9, 29, 1600) == 200);
    assert(get_local_time(TOWN_BRISBANE, 9, 29, 1601) == 201);
    
    // you should add at least 40 more assert statements 
    // to this function
    // with a comment for each test explaining it

    // there should be comment before this function
    // explaining your overall testing strategy
}


//Reference

// Below are useful information that I found from Time And Date, 
//URL:https://www.timeanddate.com/time/change/australia 
//and https://www.timeanddate.com/time/change/new-zealand
/* AUSTRALIA
1 Apr 2018 - Daylight Saving Time Ends
When local daylight time is about to reach
Sunday, 1 April 2018, 3:00:00 am clocks are turned backward 1 hour to 
Sunday, 1 April 2018, 2:00:00 am local standard time instead.

7 Oct 2018 - Daylight Saving Time Starts
When local standard time is about to reach
Sunday, 7 October 2018, 2:00:00 am clocks are turned forward 1 hour to 
Sunday, 7 October 2018, 3:00:00 am local daylight time instead.*/

/* NEW ZEALAND
1 Apr 2018 - Daylight Saving Time Ends
When local daylight time is about to reach
Sunday, 1 April 2018, 3:00:00 am clocks are turned backward 1 hour to 
Sunday, 1 April 2018, 2:00:00 am local standard time instead.

30 Sep 2018 - Daylight Saving Time Starts
When local standard time is about to reach
Sunday, 30 September 2018, 2:00:00 am clocks are turned forward 1 hour 
to Sunday, 30 September 2018, 3:00:00 am local daylight time instead.*/
