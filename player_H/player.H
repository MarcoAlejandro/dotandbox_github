#ifndef PLAYER_H
#define PLAYER_H
/**
@file player.H

@brief Declarations on C++ of class player, for application in 
game dot and boxes.

@author CODEMAKERS

@date 03/11/2016
*/

class player
{
private:

	std::string id; //name of player
	uint score;		//score of player
	uint record;	//record of player

public:

	/**
		@brief constructor funtion of class player.
	*/
	player()
	{
		this->id = "";
		this->score = 0;
		this->record = 0;
	}

	/**
		@brief see the id attribute
		@return player id
	*/
	std::string get_id()
	{
		return(this->id);
	}

	/**
		@brief see the id attribute Player
		@return player id
	*/
	uint get_score()
	{
		return(this->score);
	}

	/**
		@brief see the record attribute Player
		@return player record
	*/
	uint get_record()
	{
		return(this->record);
	}

	/**
		@brief set the player name
		@param id = name of player
	*/
	void set_id(std::string id)
	{
		this->id = id;
	}

	/**
		@brief set the player score
		@param scr = score of player
	*/
	void set_score(uint scr)
	{
		this->score = scr;
	}

	/**
		@brief set the player record
		@param scr = record of player
	*/
	void set_record(uint rec)
	{
		this->record = rec;
	}

	/**
		@brief class destroyer player
	*/
	~player(){}
};

#endif