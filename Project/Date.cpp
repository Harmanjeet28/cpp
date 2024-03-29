//Harmanjeet Singh Hara
//Student ID#:118624220 , email: hhara@myseneca.ca


#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"

using namespace std;
namespace sdds {
    //Add the following global variable (for testing purposes) to the top of the sdds namespace in Date.cpp.
    bool sdds_test = false;
    int sdds_year = 2023;
    int sdds_mon = 12;
    int sdds_day = 25;


    bool Date::validate() {
        errCode(NO_ERROR);
        if (m_year < MIN_YEAR || m_year > m_CUR_YEAR+1) {
            errCode(YEAR_ERROR);
        }
        else if (m_mon < 1 || m_mon > 12) {
            errCode(MON_ERROR);
        }
        else if (m_day < 1 || m_day > mdays()) {
            errCode(DAY_ERROR);
        }
        return !bad();
    }
    int Date::mdays()const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
    }

    //replace systemYear and setToToday methods with the following:
    int Date::systemYear()const {
        int theYear = sdds_year;
        if (!sdds_test) {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            theYear = lt.tm_year + 1900;
        }
        return theYear;
    }
    void Date::setToToday() {
        if (sdds_test) {
            m_day = sdds_day;
            m_mon = sdds_mon;
            m_year = sdds_year;
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            m_day = lt.tm_mday;
            m_mon = lt.tm_mon + 1;
            m_year = lt.tm_year + 1900;
        }
        errCode(NO_ERROR);
    }


    int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
        int ty = m_year;
        int tm = m_mon;
        if (tm < 3) {
            ty--;
            tm += 12;
        }
        return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
    }
    Date::Date() :m_CUR_YEAR(systemYear()) {
        setToToday();
    }
    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }
    const char* Date::dateStatus()const {
        return DATE_ERROR[errCode()];
    }
    int Date::currentYear()const {
        return m_CUR_YEAR;
    }
    void Date::errCode(int readErrorCode) {
        m_ErrorCode = readErrorCode;
    }
    int Date::errCode()const {
        return m_ErrorCode;
    }
    bool Date::bad()const {
        return m_ErrorCode != 0;
    }

    ostream& operator<<(ostream& os, const Date& RO) {
        return RO.write(os);
    }
    istream& operator>>(istream& is, Date& RO) {
        return RO.read(is);
    }

  
    istream& Date::read(istream& is) {
        // Clears the error code by setting it NO_ERROR
        errCode(NO_ERROR);
        // Reads the year, the month, and the day member variables using istream and ignores a single character after the year and the month values to bypass the slashes.
        int year, month, day;
        char character;
        is >> year >> character >> month >> character >> day;
        m_year = year;
        m_mon = month;
        m_day = day;
        // Checks if istream has failed. If it did fail, it will set the error code to CIN_FAILED and clears the istream. If not, it will validate the values entered.
        if (!is)
        {
            errCode(CIN_FAILED);
           
        }
        else {
            validate();
        }

        // Returns the istream object
        return is;
    }

    //It will return true if the date is valid and false if it is not.
    Date::operator bool() const {
        return (!bad());
    }

    int Date::fetchDay()const {
        return daysSince0001_1_1();
    }

    bool operator==(const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() == rhs.fetchDay());
    }

    bool operator!=(const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() != rhs.fetchDay());
    }

    bool operator>=(const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() >= rhs.fetchDay());
    }
    bool operator<= (const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() <= rhs.fetchDay());
    }

    bool operator>(const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() > rhs.fetchDay());
    }
    bool operator<(const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() < rhs.fetchDay());
    }

    //Returns the difference between two Dates in days.
    int operator-(const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() - rhs.fetchDay());
    }



    ostream& Date::write(ostream& os) const {
        // If the Date object is in a "bad" state (it is invalid), print the "dateStatus()".
        if (bad()) {
            os << dateStatus();
        }
        else {
            os << m_year << "/"  << setfill('0') << setw(2) << right << m_mon << "/" << setfill('0') << setw(2) << right<<m_day;
        }
        return os;
    }

 


}