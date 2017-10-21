package shiyan;

import java.util.Scanner;

//import java.util.Scanner;

public class shiyanone {
	static Scanner s = new Scanner(System.in);
	public static int year = s.nextInt();
	int year1 = year;
	
	public static int month = s.nextInt();
	public static int day = s.nextInt();
	static String all = ""+year+"/"+month+"/"+day;
	
	public boolean flag = false;
    public static void main(String[] args) {
			System.out.println("前一天:" + new shiyanone().getLastDay(all));
	}

//	public void test() {
//	System.out.println("前一天:" + new shiyanone().getLastDay(all));
//	}
//	public void year() {
//		System.out.println("年份错误，请重新输入！");
//	}

    public void year() {
    	System.out.println("test");
    }
    public void month() {
    	System.out.println("genius");
    }
	public String getLastDay(String datestr) {
	String[] date = datestr.split("/");
	String dateString = null;
	year = Integer.parseInt(date[0]);
	month = Integer.parseInt(date[1]);
	day = Integer.parseInt(date[2]);
	day = day - 1;
	if(year<1960||year>2050) {
	System.out.println("年份错误，请重新输入!");
	return null;
	}
	if(month<1||month>12) {
		System.out.println("月份错误，请重新输入！");
		return null;}
	if(year%4!=0&&month==2&&day>27) {
		System.out.println("请检测该年是否为闰年，或天数超过29！");
		return null;
	}
	if((year%4==0) && (month==2) && (day>28))
	{
		System.out.println("该年为闰年，天数不可以大于29");
		return null;
	}
//	if(month==2&&day==29) {
//		return null;
//	}
	if(day<1||day>31) {
		System.out.println("日期错误！");
		return null;
	}
	
	if((month==3||month==6||month==9||month==11)&&day>29) {
		System.out.println("日期错误，请检测本月最大天数！");
	return null;}
	if (day == 0) {
	month = month - 1;
	if (month == 0) {
	year = year - 1;
	}
	}
	if (month == 0) {
	month = 12;
	}
	if (day == 0) {
	day = getDayByMonth(year, month);
	}
	dateString = year + "/" + month + "/" + day;
	return dateString;
	}

	public boolean isLeapYear(int year) {
	flag = false;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
	flag = true;
	}
	return flag;
	}

	public int getDayByMonth(int year, int month) {
	int day = 0;
	int[] daybymonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2) {
	if (isLeapYear(year)) {
	day = 29;
	} else {
	day = 28;
	}
	} else {
	day = daybymonth[month - 1];
	}
	return day;

	}

}
