#include Weapon.h
    
    /**
    Define a Weapon by its atributes
    */
    Weapon::Weapon (int Type, int MT, int Hit, int Crit, int MinRange, int MaxRange, bool IsPhysical, Skill Skill): this->type(type), this->minRange(MinRange), this->maxRange(MaxRange), this->mt(MT), this->hit(Hit), this->isPhysical(IsPhysical), this->skill(Skill) {
    }
    /**
    *   Define a weapon by its ID
    */
    Weapon::Weapon(int weaponID) {
        if (weapons == null) {
            InitializeWeapons();
        }
        /*
        this->type = weapons[weaponID].type;
        this->mt = weapons[weaponID].mt;
        this->hit = weapons[weaponID].hit;
        this->crit = weapons[weaponID].crit;
        this->minRange = weapons[weaponID].minRange;
        this->maxRange = weapons[weaponID].maxRange;
        this->isPhysical = weapons[weaponID].isPhysical;
        this->skills = weapons[weaponID].skills;    
        */        
        memcpy(this*, &weapons[weaponID], sizeof weapon); //this weapon is now a duplicate of whatever template weapon we have.
    }
    Weapon::InitializeWeapons() {
        if (weapons != null) {
            int numlines = 0;
            std::ifstream file("Weapons.dat");
            for(std::string line; getline(file, line); ) {//count the lines
                numlines++;                
            }
            file.clear(); //reset the stream
            file.seekg(0, ios::beg);
            weapons = (Weapon*) malloc(sizeof Weapon * numlines);
            numlines = 0;
            for(std::string line; getline(file, line); ) {//count the lines
                std::stringstream stream(line);
                int type;
                int mt;
                int hit;
                int crit;
                int minRange;
                int maxRange;
                int isPhysical;
                int skill;
                stream >> type;
                stream >> mt;
                stream >> hit;
                stream >> crit;
                stream >> minRange;
                stream >> maxRange;
                stream >> isPhysical;
                stream >> skill;                
                weapons[numlines] = new Weapon(type, mt, hit, crit, minRange, maxRange, isPhysical, Skills.getSkill(skill));  
            }

        }
    }
    
    
    void Weapon::use(){};
    int getType() {
        return this->type;
    };
    int Weapon::getName(){
        return this->name;
    };
    int Weapon::getDamage() {
        return this->damage;
    };
    int Weapon::getMinRange(){
        return this->minRange;
    };
    int Weapon::getMaxRange() {
        return this->maxRange;
    };
    int Weapon::getAccuracy() {
        return this->accuracy;
    };
    bool Weapon::isPhysical(){
        return this->isPhysical
    };
    void equipTo(*Unit unit) {
        unit->addSkill(skill);
    };
    void unequipFrom(*Unit) {
        unit->removeSkill(Skill);
    }