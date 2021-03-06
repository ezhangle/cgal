
#include <CGAL/Simple_cartesian.h>
#include <CGAL/property_map.h>
#include <CGAL/IO/read_off_points.h>
#include <CGAL/IO/read_xyz_points.h>

#include <vector>
#include <cstdlib>
#include <fstream>

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_3 Point_3;
typedef Kernel::Vector_3 Vector_3;
typedef std::pair<Point_3, Vector_3> PointVectorPair;

bool read(std::string s)
{
  std::ifstream fs(s.c_str());
  std::vector<PointVectorPair> pv_pairs;
  return CGAL::read_xyz_points_and_normals(fs, 
                                           back_inserter(pv_pairs), 
                                           CGAL::First_of_pair_property_map<PointVectorPair>(), 
                                           CGAL::Second_of_pair_property_map<PointVectorPair>());
}



bool read(std::string s,
          std::vector<PointVectorPair>& pv_pairs)
{
  std::ifstream fs(s.c_str());

  return CGAL::read_xyz_points_and_normals(fs, 
                                           back_inserter(pv_pairs), 
                                           CGAL::First_of_pair_property_map<PointVectorPair>(), 
                                           CGAL::Second_of_pair_property_map<PointVectorPair>());
}

bool read_off(std::string s,
              std::vector<PointVectorPair>& pv_pairs)
{
  std::ifstream fs(s.c_str());

  return CGAL::read_off_points_and_normals(fs, 
                                           back_inserter(pv_pairs), 
                                           CGAL::First_of_pair_property_map<PointVectorPair>(), 
                                           CGAL::Second_of_pair_property_map<PointVectorPair>());
}


int main()
{
  std::cerr << "### There should be three errors following this line...\n";
  assert(! read("data/read_test/bug_1.xyz"));
  assert(! read("data/read_test/bug_2.xyz"));
  assert(! read("data/read_test/bug_3.xyz"));
  std::cerr << "### ... Done. Now, there should not be any error.\n";

  assert(read("data/read_test/ok_1.xyz"));
  assert(read("data/read_test/ok_2.xyz"));
  assert(read("data/read_test/ok_3.xyz"));

  std::vector<PointVectorPair> pv_pairs;

  read("data/read_test/ok_2.xyz", pv_pairs);
  assert(pv_pairs.size() == 4);
  assert(pv_pairs[0] == std::make_pair(Point_3(2,3,4), Vector_3(4,4,2)));
  assert(pv_pairs[1] == std::make_pair(Point_3(3,4,6), Vector_3(0,0,0))); 
  assert(pv_pairs[2] == std::make_pair(Point_3(3,6,7), Vector_3(3,5,6)));
  assert(pv_pairs[3] == std::make_pair(Point_3(1,3,4), Vector_3(4,6,8)));

  pv_pairs.clear();

  assert(read_off("data/read_test/ok_1.off", pv_pairs));
  assert(pv_pairs.size() == 4);
  assert(pv_pairs[0] == std::make_pair(Point_3(3,2,0), Vector_3(1,2,3)));
  assert(pv_pairs[1] == std::make_pair(Point_3(1,2,3), Vector_3(0,0,0))); 
  assert(pv_pairs[2] == std::make_pair(Point_3(4,5,6), Vector_3(0,0,0)));
  assert(pv_pairs[3] == std::make_pair(Point_3(7,8,9), Vector_3(0,0,0)));


  return 0;
}  
