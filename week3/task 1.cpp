
#include <iostream>
using namespace std;

class Course
{
public:
    virtual void duration() = 0; 
    virtual ~Course() {}
};


class OnlineCourse : public Course
{
private:
    int weeks;
    int hoursPerWeek;

public:
    OnlineCourse(int w, int h)
    {
        weeks = w;
        hoursPerWeek = h;
    }

    void duration() override
    {
        cout << "Online Course Duration:" << endl;
        cout << "Number of weeks: " << weeks << endl;
        cout << "Hours per week: " << hoursPerWeek << endl;
        cout << "Total study hours: "
            << weeks * hoursPerWeek << " hours" << endl;
    }
};


class OfflineCourse : public Course
{
private:
    int months;
    int hoursPerDay;

public:
    OfflineCourse(int m, int h)
    {
        months = m;
        hoursPerDay = h;
    }

    void duration() override
    {
        cout << "Offline Course Duration:" << endl;
        cout << "Number of months: " << months << endl;
        cout << "Hours per day: " << hoursPerDay << endl;
        cout << "Total study hours (assuming 30 days per month): "
            << months * 30 * hoursPerDay << " hours" << endl;
    }
};


int main()
{
    OnlineCourse online(8, 5);
    OfflineCourse offline(3, 4);

    online.duration();

    cout << endl;

    offline.duration();

    return 0;
}
