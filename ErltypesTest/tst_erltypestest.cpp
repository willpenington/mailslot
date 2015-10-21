/*
Mailbox
Copyright (C) 2015 Will Penington

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
USA
*/

#include <QString>
#include <QtTest>

class ErltypesTest : public QObject
{
    Q_OBJECT

public:
    ErltypesTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void conversionToAndFromBuffer_data();
    void conversionToAndFromBuffer();
};

ErltypesTest::ErltypesTest()
{
}

void ErltypesTest::initTestCase()
{
}

void ErltypesTest::cleanupTestCase()
{
}

void ErltypesTest::conversionToAndFromBuffer_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("0") << QString();
}

void ErltypesTest::conversionToAndFromBuffer()
{
    QFETCH(QString, data);
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ErltypesTest)

#include "tst_erltypestest.moc"
