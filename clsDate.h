#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "clsString.h"

using namespace std;

class clsDate
{
private:
	short _Day;
	short _Month;
	short _Year;

public:
	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string Date)
	{
		vector<string> vDate = clsString::Split(Date, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(int DayOrderInYear, short Year)
	{
		clsDate Date = GetDateFromDayOrderInYear(DayOrderInYear, Year);

		_Day = Date.Day;
		_Month = Date.Month;
		_Year = Date.Year;
	}

	void SetDay(short Day)
	{
		if (Day >= 1 && Day <= 31)
			_Day = Day;

		else
			_Day = GetSystemDate().Day;
	}

	short GetDay()
	{
		return _Day;
	}

	__declspec(property(put = SetDay, get = GetDay)) short Day;

	void SetMonth(short Month)
	{
		if (Month >= 1 && Month <= 12)
			_Month = Month;

		else
			_Month = GetSystemDate().Month;
	}

	short GetMonth()
	{
		return _Month;
	}

	__declspec(property(put = SetMonth, get = GetMonth)) short Month;

	void SetYear(short Year)
	{
		_Year = Year;
	}

	short GetYear()
	{
		return _Year;
	}

	__declspec(property(put = SetYear, get = GetYear)) short Year;

	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day = now->tm_mday;
		short Month = now->tm_mon + 1;
		short Year = now->tm_year + 1900;

		return clsDate(Day, Month, Year);
	}

	static string ToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string ToString()
	{
		return ToString(*this);
	}

	static clsDate ToDate(string strDate)
	{
		clsDate Date(1, 1, 2001);

		vector<string> vDate = clsString::Split(strDate, "/");

		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);

		return Date;
	}

	static string Format(clsDate Date, string DateFormat)
	{
		DateFormat = clsString::ReplaceWord(DateFormat, "dd", to_string(Date.Day));
		DateFormat = clsString::ReplaceWord(DateFormat, "mm", to_string(Date.Month));
		DateFormat = clsString::ReplaceWord(DateFormat, "yyyy", to_string(Date.Year));

		return DateFormat;
	}

	string Format(string DateFormat)
	{
		return Format(*this, DateFormat);
	}

	static bool IsLeapYear(short Year)
	{
		// if year is divisible by 4 AND not divisible by 100
		// OR if year is divisible by 400
		// then it is a leap year

		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}

	static short NumberOfHoursInYear(short Year)
	{
		return NumberOfDaysInYear(Year) * 24;
	}

	short NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}

	static int NumberOfMinutesInYear(short Year)
	{
		return NumberOfHoursInYear(Year) * 60;
	}

	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(_Year);
	}

	static int NumberOfSecondsInYear(short Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}

	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(_Year);
	}

	static short NumberOfDaysInMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
			return 0;

		short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
	}

	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month, _Year);
	}

	static short NumberOfHoursInMonth(short Month, short Year)
	{
		return NumberOfDaysInMonth(Month, Year) * 24;
	}

	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Month, _Year);
	}

	static int NumberOfMinutesInMonth(short Month, short Year)
	{
		return NumberOfHoursInMonth(Month, Year) * 60;
	}

	int NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Month, _Year);
	}

	static int NumberOfSecondsInMonth(short Month, short Year)
	{
		return NumberOfMinutesInMonth(Month, Year) * 60;
	}

	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Month, _Year);
	}

	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a = (Day - Month) / Year;
		short y = Year - a;
		short m = Month + (12 * a - 2);

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	static short DayOfWeekOrder(clsDate Date)
	{
		return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(_Day, _Month, _Year);
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (short i = 1; i < Month; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, Year);
		}

		TotalDays += (Day > NumberOfDaysInMonth(Month, Year) ? NumberOfDaysInMonth(Month, Year) : Day);

		return TotalDays;
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(clsDate Date)
	{
		return NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
	}

	short NumberOfDaysFromTheBeginingOfTheYear()
	{
		return NumberOfDaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
	}

	static clsDate GetDateFromDayOrderInYear(short TotalDays, short Year, bool CountEnDay = false)
	{
		clsDate Date(1, 1, Year);

		short MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

		while (TotalDays > MonthDays)
		{
			TotalDays -= MonthDays;
			Date.Month++;

			MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		Date.Day = (TotalDays > 0 ? TotalDays : 1);

		return Date;
	}

	static string DayShortName(short Day)
	{
		string Days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return Days[Day];
	}

	static string MonthShortName(short Month)
	{
		string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return Months[Month - 1];
	}

	static bool IsValid(short Day, short Month, short Year)
	{
		if (Day < 1 || Day > 31)
			return false;

		if (Month < 1 || Month > 12)
			return false;

		if (Month == 2)
		{
			if (IsLeapYear(Year))
			{
				if (Day > 29)
					return false;
			}

			else
			{
				if (Day > 28)
					return false;
			}
		}

		short DaysInMonth = NumberOfDaysInMonth(Month, Year);

		if (Day > DaysInMonth)
			return false;

		return true;
	}

	static bool IsValid(clsDate Date)
	{
		return IsValid(Date.Day, Date.Month, Date.Year);
	}

	bool IsValid()
	{
		return IsValid(_Day, _Month, _Year);
	}

	static bool IsDateBeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day ? true : false : false)) : false);
	}

	bool IsDateBeforeDate2(clsDate Date2)
	{
		return 	IsDateBeforeDate2(*this, Date2);
	}

	static bool IsDateEqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day ? true : false) : false) : false;
	}

	bool IsDateEqualDate2(clsDate Date2)
	{
		return IsDateEqualDate2(*this, Date2);
	}

	static bool IsDateAfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDateBeforeDate2(Date1, Date2) && !IsDateEqualDate2(Date1, Date2));
	}

	bool IsDateAfterDate2(clsDate Date2)
	{
		return IsDateAfterDate2(*this, Date2);
	}

	enum enCompareDate { Before = -1, Equal = 0, After = 1 };

	static enCompareDate CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDateBeforeDate2(Date1, Date2))
			return enCompareDate::Before;

		else if (IsDateAfterDate2(Date1, Date2))
			return enCompareDate::After;

		else
			return enCompareDate::Equal;
	}

	enCompareDate CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

	static bool IsLastDayInMonth(short Day, short Month, short Year)
	{
		return Day == NumberOfDaysInMonth(Month, Year);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return IsLastDayInMonth(Date.Day, Date.Month, Date.Year);
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(_Day, _Month, _Year);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return Month == 12;
	}

	static bool IsLastMonthInYear(clsDate Date)
	{
		return IsLastMonthInYear(Date.Month);
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static bool IsEndOfWeek(short Day, short Month, short Year)
	{
		return DayOfWeekOrder(Day, Month, Year) == 6;
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		return IsEndOfWeek(Date.Day, Date.Month, Date.Year);
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(_Day, _Month, _Year);
	}

	static bool IsWeekEnd(short Day, short Month, short Year)
	{
		short DayIndex = DayOfWeekOrder(Day, Month, Year);

		//weekends are fri and sat
		return (DayIndex == 5 || DayIndex == 6);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		return IsWeekEnd(Date.Day, Date.Month, Date.Year);
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(_Day, _Month, _Year);
	}

	static bool IsBusinessDay(short Day, short Month, short Year)
	{
		return !IsWeekEnd(Day, Month, Year);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		return IsBusinessDay(Date.Day, Date.Month, Date.Year);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short DaysUntilEndOfWeek(short Day, short Month, short Year)
	{
		return 6 - DayOfWeekOrder(Day, Month, Year);
	}

	short DaysUntilEndOfWeek()
	{
		return DaysUntilEndOfWeek(_Day, _Month, _Year);
	}

	static short DaysUntilEndOfMonth(short Day, short Month, short Year, bool IncludeEndDay = true)
	{
		//method 1
		clsDate CurrentDate(Day, Month, Year);
		clsDate EndOfMonthDate;

		EndOfMonthDate.Day = NumberOfDaysInMonth(Month, Year);
		EndOfMonthDate.Month = Month;
		EndOfMonthDate.Year = Year;

		return GetDiffrenceInDays(CurrentDate, EndOfMonthDate, IncludeEndDay);

		//method 2
		//if you want to include the end day add 1 at the end (+ 1)
		//return NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day;
	}

	static short DaysUntilEndOfMonth(clsDate Date, bool IncludeEndDay = true)
	{
		return DaysUntilEndOfMonth(Date.Day, Date.Month, Date.Year, IncludeEndDay);
	}

	short DaysUntilEndOfMonth(bool IncludeEndDay = true)
	{
		return DaysUntilEndOfMonth(*this, IncludeEndDay);
	}

	static short DaysUntilEndOfYear(short Day, short Month, short Year, bool IncludeEndDay = true)
	{
		//method 1
		clsDate CurrentDate(Day, Month, Year);
		clsDate EndOfYearDate;

		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Year;

		return GetDiffrenceInDays(CurrentDate, EndOfYearDate, true);

		//method 2
		//if you want to include the end day add 1 at the end (+ 1)
		//return NumberOfDaysInYear(Year) - NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
	}

	static short DaysUntilEndOfYear(clsDate Date, bool IncludeEndDay = true)
	{
		//method 1
		clsDate EndOfYearDate;

		EndOfYearDate._Day = 31;
		EndOfYearDate._Month = 12;
		EndOfYearDate._Year = Date._Year;

		return GetDiffrenceInDays(Date, EndOfYearDate, IncludeEndDay);

		//method 2
		//if you want to include the end day add 1 at the end (+ 1)
		//return NumberOfDaysInYear(Date.Year) - NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
	}

	short DaysUntilEndOfYear(bool IncludeEndDay = true)
	{
		return DaysUntilEndOfYear(*this, IncludeEndDay);
	}

	static clsDate AddOneDay(clsDate& Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date))
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}

			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}

		else
		{
			Date.Day++;
		}

		return Date;
	}

	void AddOneDay()
	{
		AddOneDay(*this);
	}

	static clsDate IncreaceDateByNDays(int Days, clsDate& Date)
	{
		for (int i = 1; i <= Days; i++)
		{
			Date = AddOneDay(Date);
		}

		return Date;
	}

	void IncreaceDateByNDays(int Days)
	{
		IncreaceDateByNDays(Days, *this);
	}

	static clsDate AddOneWeek(clsDate& Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = AddOneDay(Date);
		}

		return Date;
	}

	void AddOneWeek()
	{
		AddOneWeek(*this);
	}

	clsDate IncreaseDateByNWeeks(short Weeks, clsDate& Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = AddOneWeek(Date);
		}

		return Date;
	}

	void IncreaseDateByNWeeks(short Weeks)
	{
		IncreaseDateByNWeeks(Weeks, *this);
	}

	static clsDate AddOneMonth(clsDate& Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}

		else
		{
			Date.Month++;
		}

		if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
		{
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		return Date;
	}

	void AddOneMonth()
	{
		AddOneMonth(*this);
	}

	static clsDate IncreaseDateByNMonths(short Months, clsDate& Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = AddOneMonth(Date);
		}

		return Date;
	}

	void IncreaseDateByNMonths(short Months)
	{
		IncreaseDateByNMonths(Months, *this);
	}

	static clsDate AddOneYear(clsDate& Date)
	{
		Date.Year++;

		if (Date.Month == 2)
		{
			if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
			{
				Date.Day = 28;
			}
		}

		return Date;
	}

	void AddOneYear()
	{
		AddOneYear(*this);
	}

	static clsDate IncreaseDateByNYears(short Years, clsDate& Date)
	{
		if (Years < 1)
			return Date;

		Date.Year += Years;

		if (Date.Month == 2)
		{
			if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
			{
				Date.Day = 28;
			}
		}

		return Date;
	}

	void IncreaseDateByNYears(short Years)
	{
		IncreaseDateByNYears(Years, *this);
	}

	static clsDate AddOneDecade(clsDate& Date)
	{
		Date.Year += 10;

		if (Date.Month == 2)
		{
			if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
			{
				Date.Day = 28;
			}
		}

		return Date;
	}

	void AddOneDecade()
	{
		AddOneDecade(*this);
	}

	static clsDate IncreaseDateByNDecades(short Decades, clsDate& Date)
	{
		if (Decades < 1)
			return Date;

		Date.Year += (Decades * 10);

		if (Date.Month == 2)
		{
			if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
			{
				Date.Day = 28;
			}
		}

		return Date;
	}

	void IncreaseDateByNDecades(short Decades)
	{
		IncreaseDateByNDecades(Decades, *this);
	}

	static clsDate AddOneCentury(clsDate& Date)
	{
		Date.Year += 100;

		if (Date.Month == 2)
		{
			if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
			{
				Date.Day = 28;
			}
		}

		return Date;
	}

	void AddOneCentury()
	{
		AddOneCentury(*this);
	}

	static clsDate AddOneMillennuim(clsDate& Date)
	{
		Date.Year += 1000;

		if (Date.Month == 2)
		{
			if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
			{
				Date.Day = 28;
			}
		}

		return Date;
	}

	void AddOneMillennuim()
	{
		AddOneMillennuim(*this);
	}

	static clsDate DecreaseOneDay(clsDate& Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Day = 31;
				Date.Month = 12;
				Date.Year--;
			}

			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
			}
		}

		else
		{
			Date.Day--;
		}

		return Date;
	}

	void DecreaseOneDay()
	{
		DecreaseOneDay(*this);
	}

	static clsDate DecreaseDateByNDays(int Days, clsDate& Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByNDays(int Days)
	{
		DecreaseDateByNDays(Days, *this);
	}

	static clsDate DecreaseOneWeek(clsDate& Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseOneDay(Date);
		}

		return Date;
	}

	void DecreaseOneWeek()
	{
		DecreaseOneWeek(*this);
	}

	static clsDate DecreaseDateByNWeeks(short Weeks, clsDate& Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseOneWeek(Date);
		}

		return Date;
	}

	void DecreaseDateByNWeeks(int Weeks)
	{
		DecreaseDateByNWeeks(Weeks, *this);
	}

	static clsDate DecreaseOneMonth(clsDate& Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}

		else
		{
			Date.Month--;
		}

		if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
		{
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		return Date;
	}

	void DecreaseOneMonth()
	{
		DecreaseOneMonth(*this);
	}

	static clsDate DecreaseDateByNMonths(short Months, clsDate& Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseOneMonth(Date);
		}

		return Date;
	}

	void DecreaseDateByNMonths(short Months)
	{
		DecreaseDateByNMonths(Months, *this);
	}

	static clsDate DecreaseOneYear(clsDate& Date)
	{
		Date.Year--;

		if (Date.Month == 2)
		{
			if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
			{
				Date.Day = 28;
			}
		}

		return Date;
	}

	void DecreaseOneYear()
	{
		*this = DecreaseOneYear(*this);
	}

	static clsDate DecreaseDateByNYears(short Years, clsDate& Date)
	{
		if (Years < 1)
			return Date;

		Date.Year -= Years;

		if (Date.Month == 2)
		{
			if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
			{
				Date.Day = 28;
			}
		}

		return Date;
	}

	void DecreaseDateByNYears(short Years)
	{
		DecreaseDateByNYears(Years, *this);
	}

	static clsDate DecreaseOneDecade(clsDate& Date)
	{
		Date.Year -= 10;

		if (Date.Month == 2)
		{
			if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
			{
				Date.Day = 28;
			}
		}

		return Date;
	}

	void DecreaseOneDecade()
	{
		DecreaseOneDecade(*this);
	}

	static clsDate DecreaseDateByNDecades(short Decades, clsDate& Date)
	{
		if (Decades < 1)
			return Date;

		Date.Year -= (Decades * 10);

		if (Date.Month == 2)
		{
			if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
			{
				Date.Day = 28;
			}
		}

		return Date;
	}

	void DecreaseDateByNDecades(short Decades)
	{
		DecreaseDateByNDecades(Decades, *this);
	}

	static clsDate DecreaseOneCentury(clsDate& Date)
	{
		Date.Year -= 100;

		if (Date.Month == 2)
		{
			if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
			{
				Date.Day = 28;
			}
		}

		return Date;
	}

	void DecreaseOneCentury()
	{
		DecreaseOneCentury(*this);
	}

	static clsDate DecreaseOneMillennuim(clsDate& Date)
	{
		Date.Year -= 1000;

		if (Date.Month == 2)
		{
			if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
			{
				Date.Day = 28;
			}
		}

		return Date;
	}

	void DecreaseOneMillennuim()
	{
		DecreaseOneMillennuim(*this);
	}

	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}

	static int GetDiffrenceInDays(clsDate Date1, clsDate Date2, bool InculdeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDateBeforeDate2(Date1, Date2))
		{
			Swap(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDateBeforeDate2(Date1, Date2))
		{
			Days++;

			Date1 = AddOneDay(Date1);
		}

		return (InculdeEndDay ? ++Days : Days) * SwapFlagValue;
	}

	int GetDiffrenceInDays(clsDate Date2, bool InculdeEndDay = false)
	{
		return GetDiffrenceInDays(*this, Date2, InculdeEndDay);
	}

	static int CalculateAgeInDays(clsDate DateOfBirth)
	{
		return GetDiffrenceInDays(DateOfBirth, GetSystemDate(), true);
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		short Days = 0;

		while (IsDateBeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
			{
				Days++;
			}

			DateFrom = AddOneDay(DateFrom);
		}

		return Days;
	}

	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{
		short Days = 0;

		while (IsDateBeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}

		return Days;
	}

	static clsDate CalculateVacationReturnDate(short VacationDays, clsDate DateFrom)
	{
		//method 1
		while (VacationDays > 0)
		{
			if (IsBusinessDay(DateFrom))
			{
				VacationDays--;
			}

			DateFrom = AddOneDay(DateFrom);
		}

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = AddOneDay(DateFrom);
		}

		return DateFrom;

		//method 2
		//short WeekendsCounter = 0;

		//for (short i = 1; i <= VacationDays; i++)
		//{
		//	if (IsWeekEnd(DateFrom))
		// {
		//		++WeekendsCounter;
		// }

		//	DateFrom = AddDateByOneDay(DateFrom);
		//}

		//for (short i = 1; i <= WeekendsCounter; i++)
		//{
		//	DateFrom = AddDateByOneDay(DateFrom);
		//}

		//while (IsWeekEnd(DateFrom))
		//{
		//	DateFrom = AddDateByOneDay(DateFrom);
		//}

		//return DateFrom;
	}

	static void PrintMonthCalender(short Month, short Year)
	{
		//total days in the month
		short NumberOfDays = NumberOfDaysInMonth(Month, Year);

		//index of the day from 0 to 6
		short CurrentDay = DayOfWeekOrder(1, Month, Year);

		//print the current month name
		printf("\n ________________%s________________\n\n", MonthShortName(Month).c_str());

		//print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		//print the appropriate spaces
		for (short i = 0; i < CurrentDay; i++)
		{
			cout << "     ";
		}

		for (short i = 1; i <= NumberOfDays; i++)
		{
			printf("%5d", i);
			//cout << setw(5) << i;

			if (++CurrentDay == 7)
			{
				cout << "\n";

				CurrentDay = 0;
			}
		}

		cout << "\n ___________________________________\n";
	}

	static void PrintMonthCalender(clsDate Date)
	{
		PrintMonthCalender(Date.Month, Date.Year);
	}

	void PrintMonthCalender()
	{
		PrintMonthCalender(_Month, _Year);
	}

	static void PrintYearCalender(short Year)
	{
		cout << "\n ___________________________________\n\n";
		cout << "          Calender - " << Year;
		cout << "\n ___________________________________\n";

		for (short i = 1; i <= 12; i++)
			PrintMonthCalender(i, Year);
	}

	static void PrintYearCalender(clsDate Date)
	{
		PrintYearCalender(Date.Year);
	}

	void PrintYearCalender()
	{
		PrintYearCalender(_Year);
	}

	void Print()
	{
		cout << ToString() << endl;
	}

};