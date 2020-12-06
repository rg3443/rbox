#include "CWorld.h"
#include "../../Sup/Logs/cLog.h"
#include <sstream>
//#include "Sup/TrueRandom/ctruerandom.h"
//#include <boost/


void CWorld::personListClanListPostInit_()
{
    printf("postinit\n");
    //PERSONS INIT
	int chance_to_enter = 100 / clanList.size(); //maybe func?
    trand randLocation;
    printf("postinit\n");
    randLocation.Init(30,60);
    printf("postinit\n");
	for(int person_id=0;person_id<personList.size();person_id++)
	{
        CPerson * person = personList.get_person(person_id);
		cout << "STARTING SEARCHING CLAN FOR PERSON WITH ID#" << person_id << endl;
		bool enter_done = false;
		int attemp_counter = 0;
		cout << person_id << endl;
		while(!enter_done)
		for(int clan_id=0;clan_id<clanList.size();clan_id++)
		{
    printf("postinitSUAKAUSAKS\n");
            //randomDevice->Init(1,101);
    printf("postinitSUAKAUSAKS\n");
    system("PAUSE");
			int randval = rand() % 101;
			if(randval < chance_to_enter)
			{
				CClan * clan = clanList.get_clan(clan_id);
				clan->add_member(person);
				enter_done = true;
				cout << "STATUS: PERSON WITH ID" << person_id <<endl;
				cout << "\tENTERED A CLAN WITH ID" << clan_id << endl;
                system("PAUSE");
			} else {
				attemp_counter++;
				cout << "\tNOTHING HAPPEND!" << "ATTEMP #" << attemp_counter <<  endl;
				//if(attemp_counter > 10) cout << "WTF????" << endl;
			}
			if(enter_done) break; // dont allow to enter two or more clans
		}
		//where leaving
		int randLoccationPosX = rand() % 30+30;
		int randLoccationPosY = rand() % 30+30;//rand() % 30+30;
        CLocation * newHome = &locations[randLoccationPosY][randLoccationPosX];
        newHome->AddPerson(person);
        person->set_current_location(newHome->GetX(),newHome->GetY());
		cout << "\tLOCATION CHOOSEN:X" << randLoccationPosX << "|Y:" << randLoccationPosY << "|PID:" << person_id << endl;
        cout << "person with id#" << person->GetId() << " suck dick and go to loca x#" << newHome->GetX() << "|y#"<<newHome->GetY() << endl;
    }
}

void CWorld::Init(trand * randomDevice)
{
    printf("cworld init\n");
    //trash
    savesCounter = 0;//???
    // first of all

    chunkList.Init();
	personList.init(PERSON_AMMOUNT);
    printf("cworld init...5%\n");
    propertyList.Init(&personList,this->GetLocMap());
    printf("cworld init...6%\n");

    this->_InitLocations();
    printf("cworld init...7%\n");

	personList.init(PERSON_AMMOUNT);
    printf("cworld init...8%\n");
    printf("cworld init...9%\n");

    chunkList.Init();
    printf("cworld init...10%\n");

	personList.init(PERSON_AMMOUNT);
    printf("cworld init...20%\n");

	clanList.init(CLAN_AMMOUNT);
    printf("cworld init...30%\n");

    backgroundList.Init();
    printf("cworld init...40%\n");

    this->personListClanListPostInit_();
    printf("cworld init...50%\n");

    eventList.Init(&backgroundList);
    printf("cworld init...60%\n");

	turnChecker.Init(&personList,&propertyList,this->GetLocMap());
    printf("cworld init...70%\n");

	//show all locations info
    this->_CheckLocationTypes();
    printf("cworld init...80%\n");

    this->_dropLocationData();
    printf("cworld init...90%\n");

    this->_dropEventData();
    cout << "init done" << endl;
}
#include "../../Sup/Logs/cLog.h"
#include <sstream>
void CWorld::_InitLocations()
{
    propertyList.Init(&personList,this->GetLocMap());
    //Logys rlog;
   //rlog.open("location_init_log.txt");
    //todo:111
    int tileCounter = 0;
    locations.resize(LOCATION_SIZE);
    for (int y=0;y<LOCATION_SIZE;y++) {
        locations[y].resize(LOCATION_SIZE);
        for(int x=0;x<LOCATION_SIZE;x++) {
            locations[y][x].Init(x,y,0);
            // CChunk init
            for(int chunky=0;chunky<CHUNK_AMMOUNT;chunky++) {
                for(int chunkx=0;chunkx<CHUNK_AMMOUNT;chunkx++) {
                    CChunk* newChunk = chunkList.RandomiseChunk(locations[y][x].GetLocationType());

                    if((chunkx*CHUNK_SIZE) != (99-CHUNK_SIZE) || (chunky*CHUNK_SIZE) != (99-CHUNK_SIZE))
                    locations[y][x].SetTiles(newChunk,(chunkx*CHUNK_SIZE),(chunky*CHUNK_SIZE));

                   // printf("Chunk inited: LX%d|LY%d|CX%d|CY%d|TILE_AMMOUNT=%d\n",x,y,(chunkx*CHUNK_SIZE),(chunky*CHUNK_SIZE),tileCounter);
                    //printf("\tchunk was inited\n");
                    tileCounter = 0;
                }
                //printf("\tchunk was inited\n");
            }
            // CProperty init
            //взятие колва проп в списке
            //прохождение и засовывание всего
            for(int propid=0;propid<locations[y][x].GetPropertyAmmount();propid++) {
                SProperty* property = locations[y][x].GetProperty(propid);
                propertyList.AddProperty(property);
                //this->_addPropertyData(property->id, property->location_pos.x, property->location_pos.y, property->GetLeftUpperTileCords(), property->GetRightDownTileCords(),-1);
            }
        }
        printf("new yrek heh\n");
    }
    printf("LOCATIONS INTED\N");
}

SLocationMap CWorld::GetLocMap()
{
    SLocationMap map;
    map.locations.resize(locations.size());
    for(int y=0;y<locations.size();y++) {
        map.locations[y].resize(locations[y].size());
        for(int x=0;x<locations[y].size();x++) {
            map.locations[y][x] = &locations[y][x];
        }
    }
    return map;
}

void CWorld::_MadeTurn(int turnVal)
{
    //todo:
    //string command = "create table events();"
//    cout << "madeturn started" << endl;
    for(int locIdY=0;locIdY<locations.size();locIdY++)
    {
        for(int locIdX=0;locIdX<locations[locIdY].size();locIdX++)
        {
            CLocation * currentLocation = &locations[locIdY][locIdX];
            SConsequences totalConseq;
            totalConseq.Clear();
            if(currentLocation->GetPersonAmmount() != 0) //INACHE SUKA NEKOMU BIT PRICHINOY EVENTA
            for(int eventId=0;eventId<AMMOUNT_EVENTS_PER_TURN;eventId++)
            {
                //cout << "event randomize started|id" << eventId << "|locx" << locIdX << "|locy" << locIdY << endl;
                CEvent * incomeEvent = eventRandomiser.GetNextEventId(&eventList,currentLocation,&backgroundList);
                //cout << "event randomize ended" << endl;
                //cout << incomeEvent->GetSlot(0)->personalConsequences.woundsChance.second << endl;
				if(incomeEvent != nullptr) {
                    CEventChain eventChain(incomeEvent->GetName(),*incomeEvent,currentLocation->GetLocationStatus(),currentLocation);
					for(int actorId=0;actorId<incomeEvent->GetActorsAmmount();actorId++)
					{
						//todo:сначалая засунуть инициатора, затем остальных
						//todo: берется ранд айди на локации, а запрашивается по всему  листу1!!!! done
						if(currentLocation->GetPersonAmmount() != 0) {
                            //Potok device(1,0,currentLocation->GetPersonAmmount()-1);
                            randomDevice->Init(0,currentLocation->GetPersonAmmount()-1);
							int randomPersonId = randomDevice->_rand();
							//cout << "id person" << randomPersonId << endl;
							CPerson * actingPerson = personList.get_person(currentLocation->GetPerson(randomPersonId)->GetId());
							currentLocation->AddActingPersonId(currentLocation->GetPerson(randomPersonId)->GetId());
							eventChain.AddMember(actingPerson);
						}

					}

					eventChain.CalculateResults();
                    this->_addEventData(turnVal,cords(locIdX,locIdY),incomeEvent->GetName());
					totalConseq.AddPoints(*(eventChain.GetExitResult()));
				}
            }
            currentLocation->RecalculateSituation();
            currentLocation->GetLocationSituation()->AddPoints(totalConseq);
            this->_addLocationData(turnVal,cords(locIdX,locIdY),currentLocation->GetPersonAmmount(),currentLocation->GetLocationSituation());
        }
    }
    //propertyList.CheckOwners();
    //personList.CheckAlive(this->GetLocMap());
//    cout << "check turn started" << endl;
	turnChecker.CheckTurn();
    this->_rebuildDbTables();
//    cout << turnVal << "'th turn maded" << endl;
}

void CWorld::_firstCreateTables()
{
//    connTool.ExecCommand("drop table personas;");
//    connTool.ExecCommand("create table personas(id integer,fname text,sname text,rolecode1 integer,rolecode2 integer,background text,CurPosX integer,CurPosY integer,cash integer,wounds integer,death integer,fame integer,influence integer);");
//    connTool.ExecCommand("drop table locations;");
//    connTool.ExecCommand("create table locations(id integer,xpos integer,ypos integer,population integer,type text);");
    //connTool.ExecCommand("create table scopedproperty(id integer,global_pos_X integer,global_pos_Y integer,left_upper_tile_X integer,left_upper_tile_Y integer,right_down_tile_X integer,right_down_tile_Y integer,owner_id integer);");///*,owner_id integer,type text

}

void CWorld::_rebuildDbTables()
{
    //connTool.ExecCommand("drop table personas;");
    //connTool.ExecCommand("create table personas(id integer,fname text,sname text,rolecode1 integer,rolecode2 integer,background text,CurPosX integer,CurPosY integer,cash integer,wounds integer,death integer,fame integer,influence integer);");
    //connTool.ExecCommand("drop table locations;");
    //connTool.ExecCommand("create table locations(id integer,xpos integer,ypos integer,population integer,type text);");
    //  PERSONS TABLE
    for(int person_id=0;person_id<personList.size();person_id++)
    {
        CPerson * person = personList.get_person(person_id);
        /*
            insert into db
        */
        string fname = person->GetFname();
        string sname = person->GetSname();
        int rlcode1 = person->GetRolecode(0);
        int rlcode2 = person->GetRolecode(1);
        string backgr = person->GetBackground()->get_name();
        int posx = person->GetCurrLocX();
        int posy = person->GetCurrLocY();
        int money = person->GetMoney();
        int wounds = person->GetWounds();
        int death = person->GetDeath();
        int fame = person->GetFame();
        int influence = person->GetInfluence();

        string insertCommand = "insert into personas values("+to_string(person_id)+
                                ",'"+fname+
                                "','"+sname+
                                "',"+to_string(rlcode1)+
                                ","+to_string(rlcode2)+
                                ",'"+backgr+
                                "',"+to_string(posx)+
                                ","+to_string(posy)+
                                ","+to_string(money)+
                                ","+to_string(wounds)+
                                ","+to_string(death)+
                                ","+to_string(fame)+
                                ","+to_string(influence)+
                                ");";

        //connTool.ExecCommand(insertCommand);

    }
    //  LOCATIONS TABLE
    //x38y38 first
    //for(int )
    //  EVENTS TABLE

}

void CWorld::_dropEventData()
{
    //connTool.ExecCommand("drop table scopedevent;");
    //connTool.ExecCommand("create table scopedevent(turn integer,xpos integer, ypos integer,name text);");
}

void CWorld::_addEventData(int turn,cords pos,string name)
{
    string command = "insert into scopedevent values("
            +to_string(turn)+","
            +to_string(pos.x)+","
            +to_string(pos.y)+","
            +"'"+name+"'"
            +");";
    //connTool.ExecCommand(command);
}

void CWorld::_dropLocationData()
{
    //connTool.ExecCommand("drop table scopedlocation;");
    //connTool.ExecCommand("create table scopedlocation(turn integer,xpos integer,ypos integer,person_ammount integer,peace_meet float,threat float,deal float,negotiation float,incident float);");
}

void CWorld::_addLocationData(int turn,cords locationPos,int personAmmount,SConsequences * currentConseq)
{
    string command = "insert into scopedlocation values("
            +to_string(turn)+","
            +to_string(locationPos.x)+","
            +to_string(locationPos.y)+","
            +to_string(personAmmount)+","
            +to_string(currentConseq->peaceMeetChance)+","
            +to_string(currentConseq->threatChance)+","
            +to_string(currentConseq->dealChance)+","
            +to_string(currentConseq->negotiationChance)+","
            +to_string(currentConseq->incidentChance)
            +");";
    //connTool.ExecCommand(command);
}

void CWorld::_addPropertyData(int turn,int id,int globalPosX, int globalPosY, cords leftUperTile, cords rightDownTile,int personOwnerId/*, int type*/)
{
    //cout << "rebuild property id " << id << endl;
    string command = "insert into scopedproperty values("
            +to_string(turn)+","
            +to_string(id)+","
            +to_string(globalPosX)+","
            +to_string(globalPosY)+","
            +to_string(leftUperTile.x)+","
            +to_string(leftUperTile.y)+","
            +to_string(rightDownTile.y)+","
            +to_string(rightDownTile.x)+","
            +to_string(personOwnerId)+");";
            //+to_string(type)+");";
    //connTool.ExecCommand(command);
}

void CWorld::_rebuildPropertyData(int turnVal)
{
    //this->_dropPropertyData();
    for(int i=0;i<propertyList.GetSize();i++) {
        SProperty* prop = propertyList.GetProperty(i);
        this->_addPropertyData(turnVal,prop->id,prop->location_pos.x,prop->location_pos.y,prop->GetLeftUpperTileCords(),prop->GetRightDownTileCords(),prop->ownerId);
    }
}

void CWorld::_dropPropertyData()
{
    //connTool.ExecCommand("drop table scopedproperty;");
    //connTool.ExecCommand("create table scopedproperty(turn integer,id integer,global_pos_X integer,global_pos_Y integer,left_upper_tile_X integer,left_upper_tile_Y integer,right_down_tile_X integer,right_down_tile_Y integer,owner_id integer);");///*,owner_id integer,type text
}

void CWorld::__SaveWorldInfo()
{
    personList.SaveData(savesCounter);
    savesCounter++;
}

void CWorld::_CheckLocationTypes()
{
    int cityCount = 0, villageCount = 0,wildsCount = 0;
    int allPersonAmmount = 0, vilcitAmmount = 0, averagePersonAmmount;
    int locationCounter = 0;
    for(int y=0;y<locations.size();y++)
    {
        for(int x=0;x<locations[y].size();x++)
        {
            CLocation * location = &locations[y][x];
            int personAmmount = location->GetPersonAmmount();
            if(personAmmount != 0) allPersonAmmount += personAmmount;

            string locaType;
            if(personAmmount > 30) {
                location->SetType(CITY);
                locaType = "City";
                cityCount++;
            } else if(personAmmount > 10) {
                location->SetType(VILLAGE);
                locaType = "Village";
                villageCount++;
            } else {
                location->SetType(WILDS);
                locaType = "Wilds";
                wildsCount++;
            }
            string insertCommand = "insert into locations values("+to_string(locationCounter)+","+to_string(x)+","+to_string(y)+","+to_string(location->GetPersonAmmount())+",'"+locaType+"');";
//            connTool.ExecCommand(insertCommand);
            locationCounter++;
        }
    }
    vilcitAmmount = cityCount + villageCount;
    averagePersonAmmount = allPersonAmmount / vilcitAmmount;
    stringstream ss1,ss2,ss11;
    ss11 << averagePersonAmmount;
    string averagePersonStr;
    ss11 >> averagePersonStr;
    averagePersonStr = "AVERAGE POPULATION:" + averagePersonStr + "\n";

    ss1 << cityCount;
    string cityAmmount;
    ss1 >> cityAmmount;
    cityAmmount = "CITY AMMOUNT:" + cityAmmount + "\n";

    ss2 << villageCount;
    string villageAmmount;
    ss2 >> villageAmmount;
    villageAmmount = "VILLAGE AMMOUNT:" + villageAmmount + "\n";
}
