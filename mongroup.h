#ifndef _MONGROUP_H_
#define _MONGROUP_H_

#include "mtype.h"
#include <vector>
#include <map>
#include "json.h"

typedef std::map<std::string, std::pair<int,int> > FreqDef;
typedef FreqDef::iterator FreqDef_iter;

void init_translation();

struct MonsterGroup
{
    std::string name;
    std::string defaultMonster;
    FreqDef  monsters;
};

struct mongroup {
 std::string type;
 int posx, posy, posz;
 unsigned char radius;
 unsigned int population;
 bool dying;
 bool diffuse;   // group size ind. of dist. from center and radius invariant
 mongroup(std::string ptype, int pposx, int pposy, int pposz, unsigned char prad,
          unsigned int ppop) {
  type = ptype;
  posx = pposx;
  posy = pposy;
  posz = pposz;
  radius = prad;
  population = ppop;
  dying = false;
  diffuse = false;
 }
 bool is_safe() { return (type == "GROUP_NULL" || type == "GROUP_FOREST"); };
};

class MonsterGroupManager
{
    public:
        static void LoadMonsterGroup(JsonObject &jo);
        static std::string GetMonsterFromGroup(std::string, std::vector <mtype*> *,
                                               int *quantity = 0, int turn = -1);
        static bool IsMonsterInGroup(std::string, std::string);
        static std::string Monster2Group(std::string);
        static std::vector<std::string> GetMonstersFromGroup(std::string);
        static MonsterGroup GetMonsterGroup(std::string group);

    private:
        static std::map<std::string, MonsterGroup> monsterGroupMap;
};
#endif
