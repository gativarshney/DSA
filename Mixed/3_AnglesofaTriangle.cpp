class Solution {
    double sqr(int side){
        double sideSqr = side * side;
        return sideSqr;
    }
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        int a = sides[0], b = sides[1], c = sides[2];
        vector<double> ans;
        if(a + b <= c) return ans;
        
        // The value of pi as cos(π) = -1 so inverse -> acos(-1) = π 
        // acos is the inverse cosine function, which returns the angle in radians for a given cosine value. 
        const double pi = acos(-1);

        // Using the Law of Cosines to find the angles of the triangle in radians
        double angleC = acos((sqr(a) + sqr(b) - sqr(c)) / (2 * a * b));
        double angleA = acos((sqr(c) + sqr(b) - sqr(a)) / (2 * c * b));
        double angleB = acos((sqr(a) + sqr(c) - sqr(b)) / (2 * a * c));

        // Converting the angles from radians to degrees
        double A = angleA * (180 / pi);
        double B = angleB * (180 / pi);
        double C = angleC * (180 / pi);

        ans.push_back(A);
        ans.push_back(B);
        ans.push_back(C);

        return ans;
    }
};