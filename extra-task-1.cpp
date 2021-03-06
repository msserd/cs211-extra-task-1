#include <assert.h>
#include <iostream>
#include <cmath>

using namespace std;

double seconds_difference(double time_1, double time_2)
{

	return (time_2 - time_1);

}

double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert(minutes >= 0 && minutes <= 60);
	assert(minutes >= 0 && minutes <= 60);
	return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
	return fmod(hours, 24);
}

int get_hours(int time)
{
	return time / 3600;
}

int get_minutes(int time)
{
	return (time - get_hours(time) * 3600) / 60;
}

int get_seconds(int time)
{
	return time - get_hours(time) * 3600 - get_minutes(time) * 60;
}


double time_to_utc(int utc_offset, double time)
{
	double a = time;
	if (time - utc_offset < 0)
		a += 24;
	return a - utc_offset >= 24 ? fmod(a - utc_offset, 24) : a - utc_offset;
}

double time_from_utc(int utc_offset, double time)
{
	double a = time;
	if (time + utc_offset < 0)
		a += 24;
	return a + utc_offset >= 24 ? fmod(a + utc_offset, 24) : a + utc_offset;
}
void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	//Task 1
	cout << "Task 1\n";
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) <= DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) <= DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) <= DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) <= DBL_EPSILON);
	cout << "Tests completed" << endl;

	//Task 2
	cout << "\nTask 2\n";
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) <= DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) <= DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) <= DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) <= DBL_EPSILON);
	cout << "Tests completed" << endl;

	//Task 3
	cout << "\nTask 3\n";
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) <= DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) <= DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) <= DBL_EPSILON);
	cout << "Tests completed" << endl;

	//Task 4
	cout << "\nTask 4\n";
	assert(fabs(to_24_hour_clock(24) - 0) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48) - 0) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) <= DBL_EPSILON);
	cout << "Tests completed" << endl;

	//Task 5
	cout << "\nTask 5\n";
	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);
	cout << "Tests completed" << endl;

	//Task 6
	cout << "\nTask 6\n";
	assert(fabs(time_to_utc(+0, 12.0) - 12.0) <= DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) <= DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) <= DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) <= DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) <= DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) <= DBL_EPSILON);
	cout << "Tests completed" << endl;

	//Task 7
	cout << "\nTask 7\n";
	assert(fabs(time_from_utc(+0, 12.0) - 12.0) <= DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 12.0) - 13.0) <= DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) <= DBL_EPSILON);
	assert(fabs(time_from_utc(+6, 6.0) - 12.0) <= DBL_EPSILON);
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) <= DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 0.0) - 23.0) <= DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) <= DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 23.0) - 0.0) <= DBL_EPSILON);
	cout << "Tests completed" << endl;
	system("pause");
}
