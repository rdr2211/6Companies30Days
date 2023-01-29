/*
Company :- Amazon
15. Generate Random Point in a Circle

Given the radius and the position of the center of a circle, implement the function randPoint which generates a uniform random point inside the circle.

Implement the Solution class:

Solution(double radius, double x_center, double y_center) initializes the object with the radius of the circle radius and the position of the center (x_center, y_center).
randPoint() returns a random point inside the circle. A point on the circumference of the circle is considered to be in the circle. The answer is returned as an array [x, y].
 

Example 1:

Input
["Solution", "randPoint", "randPoint", "randPoint"]
[[1.0, 0.0, 0.0], [], [], []]
Output
[null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]

Explanation
Solution solution = new Solution(1.0, 0.0, 0.0);
solution.randPoint(); // return [-0.02493, -0.38077]
solution.randPoint(); // return [0.82314, 0.38945]
solution.randPoint(); // return [0.36572, 0.17248]
 

Constraints:

0 < radius <= 108
-107 <= x_center, y_center <= 107
At most 3 * 104 calls will be made to randPoint.
*/
class Solution {
    double radius;
    double x_center;
    double y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        this -> radius = radius;
        this -> x_center = x_center;
        this -> y_center = y_center;
    }
    /*
    Here I learned how to generate random number in double number and apply sin and cos concept using c++ language
    */
    vector<double> randPoint() {
        double ang = (double)rand() / RAND_MAX * 2 * M_PI;
        double hyp = sqrt((double)rand() / RAND_MAX) * radius;
        double per = sin(ang)*hyp;
        double bas = cos(ang)*hyp;

        vector<double> ans{x_center + bas, y_center + per};
        return ans;
    }
};

// Second using uniform_real_distribution
class Solution {
    double radius;
    double x_center;
    double y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        this -> radius = radius;
        this -> x_center = x_center;
        this -> y_center = y_center;
    }
    /*
    Here I learned how to generate random number in double number and apply sin and cos concept using c++ language
    */
    double dist(double x_r, double y_r){
        return (x_center - x_r)*(x_center - x_r) + (y_center - y_r)*(y_center - y_r);
    }
    
    vector<double> randPoint() {
        vector<double> ans(2, 0);
        double x_r = 0, y_r = 0;

        random_device rd;
        default_random_engine re(rd());

        uniform_real_distribution<double> x_unif(x_center - radius, x_center + radius);
        uniform_real_distribution<double> y_unif(y_center - radius, y_center + radius);

        bool flag = false;
        while(!flag){
            x_r = x_unif(re);
            y_r = y_unif(re);

            if(dist(x_r, y_r) < radius * radius) flag = true;
            ans[0] = x_r; ans[1] = y_r;
        }
        return ans;
    }
};

// Method third using rand() function
class Solution {
    double radius;
    double x_center;
    double y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        this -> radius = radius;
        this -> x_center = x_center;
        this -> y_center = y_center;
    }
    /*
    Here I learned how to generate random number in double number and apply sin and cos concept using c++ language
    */
    double dist(double x_r, double y_r){
        return (x_center - x_r)*(x_center - x_r) + (y_center - y_r)*(y_center - y_r);
    }
    vector<double> randPoint() {
        vector<double> ans(2, 0);
        double x_r = 0, y_r = 0;

        bool flag = false;
        while(!flag){
            x_r = ((double)rand() / RAND_MAX * (2*radius)) + x_center - radius;
            y_r = ((double)rand() / RAND_MAX * (2*radius)) + y_center - radius;

            if(dist(x_r, y_r) < radius * radius) flag = true;
            ans[0] = x_r; ans[1] = y_r;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
