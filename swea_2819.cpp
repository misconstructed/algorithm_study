/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ����
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <set>

using namespace std;

int dx[4] = {+1, -1, 0, 0};
int dy[4] = {0, 0, +1, -1};
int arr[4][4];
set<int> s;

void search(int y, int x, int count, int num) {
    num = num * 10 + arr[y][x];
    if(count == 6) {
        if(s.find(num) == s.end()) {
            s.insert(num);
        }
        return;
    }
    for(int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x >= 0 && new_x <4 && new_y >= 0 && new_y < 4)
            search(new_y, new_x, count + 1, num);
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    /*
       �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
       ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
       //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
       freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
       ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
       freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
       ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
    */
    //freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    /*
       ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        
        s.clear();
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                search(i, j, 0, 0);
            }
        }
        
        printf("#%d %d\n", test_case, s.size());

    }
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

