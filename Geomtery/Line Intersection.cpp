struct Point {
	int x,y;
};

//Function to check if point q lies between point p,r
bool onSegment(Point p, Point q, Point r) {
	if(q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;

	return false;
}

//Given 3 points returns the orientation of those 3 points
//returns:
//0 -> if points are collinear
//1 -> right turn
//2 -> left turn
int orient(Point p, Point q, Point r) {
	int val = (q.y - p.y)*(r.x - q.x) - (r.y - q.y)*(q.x - p.x);
	if(val == 0)
		return 0;
	return (val > 0)? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
	int o1 = orient(p1, q1, p2);
	int o2 = orient(p1, q1, q2);
	int o3 = orient(p2, q2, p1);
	int o4 = orient(p2, q2, q1);

	//General case
	if(o1 != o2 && o3 != o4)
		return true;

	//Special cases
	//Check if 3 points are collinear and the fourth one must lie withing the 2 points of the other line segment

	if(o1 == 0 && onSegment(p1, q2, q1))	return true;
	if(o2 == 0 && onSegment(p1, p2, q1)) 	return true;
	if(o3 == 0 && onSegment(p2, q1, q2)) 	return true;
	if(o4 == 0 && onSegment(p2, p1, q2))	return true;

	return false;
	
}

int main() {_
	
	struct Point p1 = {1,1}, q1 = {10,10};
	struct Point p2 = {10,10}, q2 = {20,20};

	cout << (doIntersect(p1, q1, p2, q2)? "Yes\n" : "No\n");//Yes
}
