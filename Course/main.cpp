#include <iostream>
#include "csv.h"
#include <unordered_map>
#include "course_graph.cpp"

int main(int argc, char* argv[]) {
    if (argc < 7) {
        std::cerr << "Передайте имя и количество курсов";
    }

    io::CSVReader<3> in(argv[1]);
    in.read_header(io::ignore_extra_column, "id", "name", "level", "dependencies", "priority");
    int id;
    int level;
    int priority;
    std::string name;
    std::string dependencies;

    std::unordered_map<int, std::pair<int, std::string>> graph_id_to_course;
    std::unordered_map<std::string, int> course_to_graph_id;
    int current_id = -1;

    CourseGraph CG(argv[2]);

    while(in.read_row(id, name, level, dependencies, priority)){
        graph_id_to_course[current_id] = std::make_pair(id, name);
        course_to_graph_id[name] = current_id;

        std::set<int> parents;
        std::stringstream deps(dependencies);
        int c_id;

        while (deps >> c_id) {
            parents.insert(c_id);
        }
        
        CG.AddNode(current_id,
                   level,
                   priority,
                   deps);
    }


    std::set<int> result = CG.GetCoursesList(course_to_graph_idargv[3]),
                                             course_to_graph_idargv[4]),
                                             course_to_graph_idargv[5]),
                                             course_to_graph_idargv[6]));

    
    for (int id : result) {
        std::cout << graph_id_to_course[id] << std::endl;
    }


    return 0;
}