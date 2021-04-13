#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <string_view>
#include <queue>

class CourseGraph {
public:
    explicit CourseGraph(size_t CoursesNum);
    void AddNode(int id,
                 int level,
                 int priopity,
                 vector<int> parents);

    std::set<int> GetCoursesList(int third_lvl_course_id1,
                                 int third_lvl_course_id2,
                                 int third_lvl_course_id3,
                                 int five_lvl_course_id);
private:
    //_______________________NODE_________________________
    struct Node {
        Node(int id,
             int level,
             int priopity,
             vector<int> parents) : id_(id),
                                         level_(level),
                                         priority_(priopity),
                                         parents_(parents) {}

        int id_;
        int level_;
        int priority_;
        vector<int> parents_;
    };
    //______________________________________________________

    int root;
    vector<std::unique_ptr<Node>> nodes;
    size_t courses_num;
    std::set<int> result_courses;
    std::vector<std::set<int>> courses_by_semesters(7, std::set<int>());

private:
    // void DivideToSemesters();
    void dfs();
};

explicit CourseGraph::CourseGraph(size_t CoursesNum) : nodes(CoursesNum),
                                                       courses_num(CoursesNum),
                                                       course_added(0) {}

void CourseGraph::AddNode(int id,
                          int level,
                          int priopity,
                          vector<int> parents) {

    nodes[id] = Node(id, level, priopity, parents);
}

std::set<int> CourseGraph::GetCoursesList(int third_lvl_course_id1,
                                          int third_lvl_course_id2,
                                          int third_lvl_course_id3,
                                          int five_lvl_course_id) {

    dfs(third_lvl_course_id1);
    dfs(third_lvl_course_id2);
    dfs(third_lvl_course_id3);
    dfs(five_lvl_course_id);

    DivideToSemesters();

    return result_courses;
}

// bool CourseGraph::HasDependenciesConflict(const std::set<int>& courses, int course_id) {
//     for () {
        
//     }
// }

// void CourseGraph::DivideToSemesters() {
//     size_t semester_num = 0;
//     for (int course_id : result_courses) {
//         if (!HasDependenciesConflict(courses_by_semesters[semester_num], course_id)) {
//             courses_by_semesters[semester_num].insert(course_id);
//         }
//     }
// }

void CourseGraph::dfs(int course_id) {
    for (int current_node : nodes[course_id]->parents_) {
        result_courses.insert(current_node);
        dfs(current_node);
    }
}