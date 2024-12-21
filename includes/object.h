#ifndef OBJECT_H
#define OBJECT_H

#include <raylib.h>
#include <unordered_map>

namespace Objects {
    enum Type {
        PLATFORM = 1,
        ENEMY = 2,
        ITEM = 3
    };
}

class Object {
public:
    Vector2 pos{};
    int id{};
    Vector2 size{};
    Color color{};

    Object(Vector2 pos, int id) : pos(pos), id(id) {
        TypeId _ = getAttrsFromID(id);
        size = _.size;
        color = _.color;
    }

    Object(Vector2 pos, int id, Vector2 size, Color color) : pos(pos), id(id), size(size), color(color) {}

private:
    struct TypeId {
        Vector2 size;
        Color color;
    };

    static TypeId getAttrsFromID(int id) {
        static std::unordered_map<int, TypeId> idToSize = {
                {Objects::PLATFORM, {{80, 10}, PURPLE}}
        };

        if (idToSize.find(id) != idToSize.end()) {
            return idToSize[id];
        }
        return {{-1, -1}, BLANK};
    }
};



#endif //OBJECT_H
