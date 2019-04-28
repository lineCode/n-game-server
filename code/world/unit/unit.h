#ifndef __UNIT_H__
#define __UNIT_H__

struct Pos
{
	float x;
	float y;
	float z;

	Pos()
	{
		x = 0;
		y = 0;
		z = 0;
	}
};
class Unit
{
public:
	Unit();
	virtual ~Unit();

	virtual void Update(float delta_time);

	SetPos(const Pos& pos);

private:
	int m_id;
	int m_level
	Pos m_pos;

	float m_speed;
}

#endif
