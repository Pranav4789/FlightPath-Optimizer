#include "utilities.h"


using namespace std;

std::vector<std::string> Split(const std::string& str, char delimiter) {
  size_t last = 0;
  std::vector<std::string> substrs;
  for (size_t i = 0; i != str.length(); ++i) {
    if (str.at(i) == delimiter || str.at(i) == '\r') {
      std::string substr = str.substr(last, i - last);
      last = i + 1;
      substrs.push_back(substr);
    }
  }

  if (last != str.size()) {
    std::string substr = str.substr(last, str.length() - last);
    substrs.push_back(substr);
  }

  return substrs;
}

long double distance(long double lat1, long double long1,
                     long double lat2, long double long2)
{
    // Convert the latitudes and longitudes from degree to radians.
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
     
    // Haversine Formula
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;
 
    long double ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
 
    // Radius of Earth in Kilometers, R = 6371 Use R = 3956 for miles
    long double R = 6371;
     
    ans = ans * R;
 
    return ans;
}

long double toRadians(const long double degree)
{
    // cmath library in C++ defines the constant
    // M_PI as the value of pi accurate to 1e-30
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

vector<string> reverse(vector<string> s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);
    return s;
}

void print_2d_vector(const vector< vector<double> > & a)
{
    size_t M = a.size();
    size_t N = a[0].size();
    int width = 0;

    /* compute the required width */
    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++) {
            int w = snprintf(NULL, 0, "%g", a[i][j]);
            if (width < w) {
                width = w;
            }
        }
    }

    /* print the arrays */
    for (size_t i = 0; i < M; i++) {
        printf("[");
        for (size_t j = 0; j < N; j++) {
            if (j != 0) printf(", ");
            printf("%*g", width, a[i][j]);
        }
        printf("]\n");
    }
}

vector<vector<double>> matrixMultiplication(const vector<vector<double>>& l, const vector<vector<double>>& r) {
    
    size_t r1 = l.size(), c1 = l[0].size(), r2 = r.size(), c2 = r[0].size();
    // If column of first matrix in not equal to row of second matrix,
    // ask the user to enter the size of matrix again.
    while (c1!=r2) {
        std::cout << "Error! column of first matrix not equal to row of second.";
        return {{-1.0}};
    }
    vector<vector<double>> ret(r1, vector<double>(c2, 0.0));
    // Multiplying matrix a and b and storing in array mult.
    for(size_t i = 0; i < r1; ++i)
        for(size_t j = 0; j < c2; ++j)
            for(size_t k = 0; k < c1; ++k) {
                ret[i][j] += l[i][k] * r[k][j];
            }
    return ret;
}