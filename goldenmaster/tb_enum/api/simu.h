#pragma once

#include <QtCore>
#include "api.h"

namespace tb_enum {

// ********************************************************************
// SimulationEnumInterface simulation interface
// ********************************************************************


class SimulationEnumInterface : public AbstractEnumInterface
{
    Q_OBJECT
public:
    explicit SimulationEnumInterface(QObject *parent = nullptr);
    virtual ~SimulationEnumInterface() override;
    Enum0::Enum0Enum prop0() const override;
    void setProp0(Enum0::Enum0Enum prop0) override;
    Enum1::Enum1Enum prop1() const override;
    void setProp1(Enum1::Enum1Enum prop1) override;
    Enum2::Enum2Enum prop2() const override;
    void setProp2(Enum2::Enum2Enum prop2) override;
    Enum3::Enum3Enum prop3() const override;
    void setProp3(Enum3::Enum3Enum prop3) override;
    Enum0::Enum0Enum func0(Enum0::Enum0Enum param0) override;
    Enum1::Enum1Enum func1(Enum1::Enum1Enum param1) override;
    Enum2::Enum2Enum func2(Enum2::Enum2Enum param2) override;
    Enum3::Enum3Enum func3(Enum3::Enum3Enum param3) override;

private:
    Enum0::Enum0Enum m_prop0;
    Enum1::Enum1Enum m_prop1;
    Enum2::Enum2Enum m_prop2;
    Enum3::Enum3Enum m_prop3;
};

} // namespace tb_enum
