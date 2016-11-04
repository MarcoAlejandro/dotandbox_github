# ifndef dot_H
# define dot_H

# include <utility>
# include <stdexcept>
using namespace std;

template<size_t F,size_t C> class dot
{
	
private:
	bool _has_left, _has_right, _has_up, _has_down;
	bool ur_corner,ul_corner,dr_corner, dl_corner, u_border, d_border, r_border, l_border;
	pair< short, short> position;

public:
	dot(){};

	//Corners constructors:
	dot(pair<short, short> pos)
	{

		if(get<0>(pos) >= F or get<1>(pos) >= C)
			throw out_of_range("position out of range");

		position = pos;
		_has_down = false;
		_has_up = false;
		_has_right = false;
		_has_left = false;

		if (get<0>(pos) == F - 1 and get<1>(pos) == C - 1)
		{
			ur_corner = false; 
			ul_corner = false;
			dr_corner = true;
			dl_corner = false;
			u_border = false;
			d_border = false;
			r_border = false;
			l_border = false;
			return;
		}

		if (get<0>(pos) == 0 and get<1>(pos) == C - 1)
		{
			ur_corner = true; 
			ul_corner = false;
			dr_corner = false;
			dl_corner = false;
			u_border = false;
			d_border = false;
			r_border = false;
			l_border = false;
			return;
		}
		if(get<0>(pos)== 0 and get<1>(pos) == 0)
		{
			ur_corner = false; 
			ul_corner = true;
			dr_corner = false;
			dl_corner = false;
			u_border = false;
			d_border = false;
			r_border = false;
			l_border = false;
			return;
		}
		if(get<0>(pos)== F - 1 and get<1>(pos) == 0)
		{
			ur_corner = false; 
			ul_corner = false;
			dr_corner = false;
			dl_corner = true;
			u_border = false;
			d_border = false;
			r_border = false;
			l_border = false;
			return;
		}

		if(get<0>(pos) == 0)
		{
			ur_corner = false; 
			ul_corner = false;
			dr_corner = false;
			dl_corner = false;
			u_border = true;
			d_border = false;
			r_border = false;
			l_border = false;
			return;
		}

		if(get<0>(pos) == F - 1)
		{
			ur_corner = false; 
			ul_corner = false;
			dr_corner = false;
			dl_corner = false;
			u_border = false;
			d_border = true;
			r_border = false;
			l_border = false;
			return;
		}

		if(get<1>(pos) == C - 1)
		{
			ur_corner = false; 
			ul_corner = false;
			dr_corner = false;
			dl_corner = false;
			u_border = false;
			d_border = false;
			r_border = true;
			l_border = false;
			return;
		}

		if(get<1>(pos) == 0)
		{
			ur_corner = false; 
			ul_corner = false;
			dr_corner = false;
			dl_corner = false;
			u_border = false;
			d_border = false;
			r_border = false;
			l_border = true;
			return;
		}

		ur_corner = false; 
		ul_corner = false;
		dr_corner = false;
		dl_corner = false;
		u_border = false;
		d_border = false;
		r_border = false;
		l_border = false;

		return;

	}

	bool has_left()
	{
		return _has_left;
	}
	bool has_right()
	{
		return _has_right;
	}
	bool has_up()
	{
		return _has_up;
	}
	bool has_down()
	{
		return _has_down;
	}

	bool is_ur_corner()
	{
		return ur_corner;
	}
	bool is_ul_corner()
	{
		return ul_corner;
	}
	bool is_dr_corner()
	{
		return dr_corner;
	}
	bool is_dl_corner()
	{
		return dl_corner;
	}

	bool is_u_border()
	{
		return u_border;
	}
	bool is_d_border()
	{
		return d_border;
	}
	bool is_l_border()
	{
		return l_border;
	}
	bool is_r_border()
	{
		return r_border;
	}


	pair<short, short> get_position()
	{
		return position;
	}

	pair<short, short> get_pos()
	{
		return position;
	}

	void mark_left()
	{
		_has_left = true;
	}
	void mark_right()
	{
		_has_right = true;
	}
	void mark_up()
	{
		_has_up = true;
	}
	void mark_down()
	{
		_has_down = true;
	}

	void set_left(bool l)
	{
		_has_left = l;
	}
	void set_right(bool r)
	{
		_has_right = r;
	}
	void set_up(bool u)
	{
		_has_up = u;
	}
	void set_down(bool d)
	{
		_has_down = d;
	}

	bool is_full()
	{
		return _has_down and _has_up and _has_right and _has_left;
	}

	bool operator == (const dot & dot_)
	{
		return get_pos() == dot_.get_pos();
	}

	void reset_dot()
	{
		_has_left = false;
		_has_right = false;
		_has_down = false;
		_has_up = false;
	}
};


#endif