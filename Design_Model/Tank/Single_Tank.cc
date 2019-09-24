#include <iostream>

using namespace std;

// 定义产品类型信息
typedef enum{
  Tank_Type_56,
  Tank_Type_58,
  Tank_Type_num
}Tank_Type;

// 抽象产品类
class Tank{
public:
  virtual const string& type() = 0;

  virtual ~Tank(){}
private:
};

// 具体产品类
class Tank56 : public Tank{
public:
  Tank56():Tank(),m_strType("Tank56") {
    
  }

  const string& type() override{
    cout << m_strType.data() << endl;
    return m_strType;
  }

private:
  string m_strType;
};

// 具体产品类
class Tank58 : public Tank{
public:
  Tank58(): Tank(), m_strType("Tank58"){

  }

  const string& type() override{
    cout << m_strType.data() << endl;
    return m_strType;
  }
private:
  string m_strType;
};


// 工厂类
class TankFactory{
public:

  Tank* createTank(Tank_Type tank){
    switch(tank){
      case Tank_Type_56 : 
        return new Tank56();
      case Tank_Type_58 :
        return new Tank58();
      default:
        return nullptr;
    }
  }
private:

};

int main(){
  TankFactory* factory = new TankFactory();
  Tank* tank56 = factory->createTank(Tank_Type_56);
  tank56->type();

  Tank* tank58 = factory->createTank(Tank_Type_58);
  tank58->type();


  delete tank56;
  tank56 = nullptr;

  delete tank58;
  tank58 = nullptr;

  delete factory;
  factory = nullptr;
  return 0;
}