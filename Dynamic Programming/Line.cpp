#include <bits/stdc++.h>
   
using namespace std;
   
typedef long long ll;
typedef long double ld;

class Line
{
private:
	int p;
	ld length=0;
	vector<double> x;
	vector<double> y;
public:
	Line()
	{
		cin >> this->p;
		cout << "Enter coordinates:\n";
		for (int i = 0; i < p; ++i)
		{
			double a,b;
			cin >> a >> b;
			x.push_back(a);
			y.push_back(b);
		}
	}
	double calculate_length()
	{
		for (auto i = x.begin(),j=y.begin(); i < x.end()-1; ++i,++j)
		{
			length+= sqrt(pow((*(i+1)-*i),2)+pow((*(j+1)-*j),2));
		}
		return length;
	}
};
int main()
{
    cout << "Number of points in Line 1: ";
    Line l1;
    double line1 = l1.calculate_length(); 
    cout << "Length of Line 1: " << line1 << endl;

    cout << "Number of points in Line 2: ";
    Line l2;
    double line2 = l2.calculate_length();
    cout << "Length of Line 1: " << line2 << endl;

    (line1>line2)? cout << "Line 1 > Line 2\n": cout << "Line 2 > Line 1\n";

    /*if we want to calc for multple Line segments:

    Line line[4]={Line(1),Line(2),Line(3),Line(4)};
    double mx=-1.0; int id;
    for (int i = 0; i <= 3; ++i)
    {
    	if(line[i].calculate_length()>mx)
    	{
    		mx= line[i].calculate_length();
    		id = i+1;
    	}
    }
    cout << "The Line with max length: " << mx << endl;*/
    return 0;
}