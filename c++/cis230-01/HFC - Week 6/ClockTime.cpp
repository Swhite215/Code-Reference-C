/*
   Spencer White
   CIS 230-02 - Clock Time
   First Test Driven Development
*/

#include <iostream>
#include <string>
#include <vector>

// Clock Time Class
class ClockTime {
    private:
        int hours;
        int minutes;

    public:
        ClockTime(int h, int m) {

            // Set Initial
            hours = h;
            minutes = m;

            // Adjust for 0 Minutes - Set to XX:59
            if (m < 0 || m > 59) {
                minutes = 59;
            }
            
            // Adjust for Out of Range Hours - Set to Max Hours
            if (h < 0 || h > 23) {
                hours = 23;
            }

        }
        std::string display() {
            // Variables to Display
            int h;
            std::string m;
            std::string meridian;

            // Determine Meridian and 12hr Value
            if(hours == 0) {
                h = 12;
                meridian = "AM";
            } else if (hours == 12) {
                h = 12;
                meridian = "PM";
            }else if (hours > 12) {
                h = hours -= 12;
                meridian = "PM";
            } else {
                h = hours;
                meridian = "AM";
            }

            // Determine Minute Value
            if (std::to_string(minutes) == "0") {
                m = "00";
            } else if (minutes < 10) {
                m = "0" + std::to_string(minutes);
            } else {
                m = std::to_string(minutes);
            }

            std::cout<<std::to_string(h) + ":" + m + " " + meridian<<std::endl;
            return std::to_string(h) + ":" + m + " " + meridian;
        }
};

// Function Prototypes
void assertThat(ClockTime t, std::string, std::string);
void displayTestReport();
void storeTest(std::string, std::string);

// Global Test Trackers
int numberOfTests = 0;
int passingTests = 0;
int failingTests = 0;
std::vector<std::string> passingTestList;
std::vector<std::string> failingTestList;

int main() {

    std::cout<<"----------Time Class Assignment----------"<<std::endl;

    // Tests for Hour Values in Range [1-12)
    for (int i = 1; i < 12; i++) {
        std::string hour = std::to_string(i);
        assertThat(ClockTime(i, 50), hour + ":50 AM", "ClockTime(" + hour + "," + "50)" + ".display()");
    }

    // Tests for All Hour Values in Range [13-24)
    for (int i = 13; i < 24; i++) {
        std::string hour = std::to_string(i - 12);
        assertThat(ClockTime(i, 10), hour + ":10 PM", "ClockTime(" + std::to_string(i) + "," + "10)" + ".display()");
    }

    // Tests for 0 Hour Values
    assertThat(ClockTime(0, 0), "12:00 AM", "ClockTime(0, 0).display()");
    assertThat(ClockTime(0, 10), "12:10 AM", "ClockTime(0, 10).display()");

    // Tests for Noon Hour Values
    assertThat(ClockTime(12, -1), "12:59 PM", "ClockTime(12, -1).display()");
    assertThat(ClockTime(12, 1), "12:01 PM", "ClockTime(12, 1).display()");

    // Tests for Invalid Hour Input
    assertThat(ClockTime(-1, 10), "11:10 PM", "ClockTime(-1, 10).display()");
    assertThat(ClockTime(24, 10), "11:10 PM", "ClockTime(24, 10).display()");
    assertThat(ClockTime(500, 10), "11:10 PM", "ClockTime(500, 10).display()");

    // Test for Invalid Minute Input
    assertThat(ClockTime(15, -1), "3:59 PM", "ClockTime(12, -1).display()");
    assertThat(ClockTime(5, 99), "5:59 AM", "ClockTime(5, 99).display()");

    // Display Test Report
    displayTestReport();

    return 0;
}

/*
   Function Description: Performs an Assertion Equality Test
   Parameters: ClockTime t, std::string expected, std::string testName
   Returns: N/A
*/
void assertThat(ClockTime t, std::string expected, std::string testName) {
    if (t.display() == expected) {
        // Store In Passing
        passingTestList.push_back(("Test: " + testName + " - Result: " + t.display()));
        passingTests++;
    } else {
        // Store In Failure
        failingTestList.push_back(("Test: " + testName + " - Result: " + t.display()));
        failingTests++;
    }

    numberOfTests++;
}

/*
   Function Description: Displays Results of Test Suite
   Parameters: N/A
   Returns: N/A
*/
void displayTestReport() {
    std::cout<<"  Report for 12hr HH:MM AM/PM Test Suite  "<<std::endl;
    std::cout<<"    Total Tests: "<<numberOfTests<<std::endl;

    // Log Passing Tests
    std::cout<<"    Passing Tests: "<<passingTests<<std::endl;
    for (std::string x : passingTestList) {
        std::cout<<"        "<<x<<std::endl;
    }

    // Log Failing Tests
    std::cout<<"    Failing Tests: "<<failingTests<<std::endl;
    for (std::string x : failingTestList) {
        std::cout<<"        "<<x<<std::endl;
    }
}