#ifndef __SCENE_H__
#define __SCENE_H__

#include <map>

struct MapInfo
{

};

class Scene
{
public:
	Scene();
	virtual ~Scene();

	bool Init();
	void UnInit();

	void OnEnter(Unit* unit);
	void OnLeave(Unit* unit);

	void BroadCast();

private:
	int m_id;
	MapInfo m_map;

	std::map<int, Unit*> m_id2unit;
};

#endif
