#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

namespace reuse
{
    struct stdate {
        short _Day;
        short month;
        short year;
    };

    struct stperiod {
        stdate start;
        stdate end;
    };

    // --- Basic utilities ---
    int ReadNumber(string msg = "Please enter a number")
    {
        int number;
        cout << msg;
        cin >> number;
        return number;
    }

    bool IsLeapYear(int year)
    {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    bool SameDate(stdate date1, stdate date2)
    {
        return (date1.year == date2.year &&
            date1.month == date2.month &&
            date1._Day == date2._Day);
    }

    // --- Date operations ---
    short HowManyDaysInMonth(short month, short year)
    {
        if (IsLeapYear(year) && month == 2)
            return 29;
        short day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return day[month - 1];
    }

    void AddDay(stdate& date)
    {
        if (date.month == 12 && date._Day == HowManyDaysInMonth(date.month, date.year)) {
            date.year++;
            date.month = 1;
            date._Day = 1;
        }
        else if (date._Day == HowManyDaysInMonth(date.month, date.year)) {
            date.month++;
            date._Day = 1;
        }
        else
            date._Day++;
    }

    void ReadDate(stdate& date)
    {
        date._Day = ReadNumber("Enter the day : ");
        date.month = ReadNumber("Enter the month : ");
        date.year = ReadNumber("Enter the year : ");
    }

    // --- Comparisons ---
    bool IsDate1BeforeDate2(stdate date1, stdate date2)
    {
        return date1.year < date2.year ? true :
            date1.year == date2.year && date1.month < date2.month ? true :
            date1.year == date2.year && date1.month == date2.month && date1._Day < date2._Day ? true : false;
    }

    bool IsDate1AfterDate2(stdate date1, stdate date2)
    {
        return date1.year > date2.year ? true :
            date1.year == date2.year && date1.month > date2.month ? true :
            date1.year == date2.year && date1.month == date2.month && date1._Day > date2._Day ? true : false;
    }

    void Swap2Dates(stdate& date1, stdate& date2)
    {
        stdate temp = date1;
        date1 = date2;
        date2 = temp;
    }

    // --- Period and overlap ---
    bool IsOverlapDates(stperiod period1, stperiod period2)
    {
        if (IsDate1BeforeDate2(period2.end, period1.start) ||
            IsDate1AfterDate2(period2.start, period1.end))
            return false;
        return true;
    }

    short OverLapDays(stperiod period1, stperiod period2)
    {
        short counter = 0;
        while (!SameDate(period1.start, period1.end))
        {
            if ((period1.start.year >= period2.start.year) && (period1.start.year <= period2.end.year) &&
                (period1.start.month >= period2.start.month) && (period1.start.month <= period2.end.month) &&
                (period1.start._Day >= period2.start._Day) && (period1.start._Day <= period2.end._Day))
                counter++;
            AddDay(period1.start);
        }
        return counter;
    }

    int DifferenceInDays(stdate& date1, stdate& date2)
    {
        int days = 0;
        short status = 1;
        if (!IsDate1BeforeDate2(date1, date2)) {
            Swap2Dates(date1, date2);
            status = -1;
        }
        while (!SameDate(date1, date2)) {
            AddDay(date1);
            days++;
        }
        return days * status;
    }

    // --- Day order functions ---
    short DayOrderInWeek(short year, short month, short day = 1)
    {
        short a = (14 - month) / 12;
        short y = year - a;
        short m = month + 12 * a - 2;
        return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
    }

    short DayOrderInWeek(stdate date)
    {
        short a = (14 - date.month) / 12;
        short y = date.year - a;
        short m = date.month + 12 * a - 2;
        return (date._Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
    }

    short DayOrderInYear(short year, short month, short day)
    {
        short counter = 0;
        for (short i = 1; i < month; i++)
            counter += HowManyDaysInMonth(i, year);
        counter += day;
        return counter;
    }

    bool IsWeekend(short order)
    {
        return (order == 5 || order == 6);
    }

    bool IsWorkDay(short order)
    {
        return !(order == 5 || order == 6);
    }

    stdate EndVacationDate(stdate date1, short VacationDays)
    {
        stdate date2 = date1;
        while (VacationDays != 0)
        {
            if (IsWorkDay(DayOrderInWeek(date2)))
                VacationDays--;
            AddDay(date2);
        }
        return date2;
    }

    // --- Display functions ---
    void calender(short year, int month)
    {
        string months[13] = { "","January","Februry","March","April","May","June","July","August","Septermper","October","November","December" };
        cout << "-----------------------------------" << months[month] << "-----------------------------------";
        cout << "\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n";

        short dayorder = DayOrderInWeek(year, month);
        int counter = 0;
        for (int i = 0; i < dayorder; i++) {
            cout << "      ";
            counter++;
        }

        short count = HowManyDaysInMonth(month, year);
        for (int i = 1; i <= count; i++) {
            if (counter == 7) {
                cout << endl;
                counter = 0;
            }
            cout << setw(6) << i;
            counter++;
        }
        cout << "\n========================================================\n";
    }

    void YearCalender(short year)
    {
        cout << "\n-----------------------------------Year " << year << "-----------------------------------\n";
        for (int b = 1; b <= 12; b++)
            calender(year, b);
    }
}

