/*
**			calculate the sailings
**	problem 1: given a start and end, calculate course and distance
**	problem 2: given a start position, course and distance, cal end position
**
**	Copyright John Holden 2nd September 1989
**	c/o -	Department of Psychology
**		University of Sydney
**		NSW, 2006
**		Australia
**
**	johnh@psych.usyd.edu.au
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

#define	EVER	; ;				/* loop for ever */

#define	TODEG(r) 	((r) * 57.2957795131)	/* convert radians to degrees */
#define TORAD(d)	((d) / 57.2957795131)	/* convert to radians */

#define	Sin(x)		sin(TORAD(x))		/* convert to radians */
#define	Cos(x)		cos(TORAD(x))		/* convert to radians */
#define	Tan(x)		tan(TORAD(x))		/* convert to radians */
#define	Asin(x)		TODEG(asin(x))		/* convert to degrees */
#define	Acos(x)		TODEG(acos(x))		/* convert to degrees */
#define	Atan(x)		TODEG(atan(x))		/* convert to degrees */
#define	Atan2(x1, x2)	TODEG(atan2(x1, x2))	/* convert to degrees */

/*
**	some macros to simply scan of position
*/

#define	SKIP_SPACES()	while(isspace(*s)) s++;
#define	SKIP_DIGITS()	while(isdigit(*s)) s++;
#define	SKIP_FLOATS()	while(isdigit(*s) || *s == '.') s++;

/*
**	structure for a position
**	Lat N and Long E are +ve
**	Lat S and Long W are -ve
*/

struct	pos
{
	double	p_lat;		/* latitude in degrees */
	double	p_long;		/* longitude in degrees */
};

/*
**	table to us various ellipsoids
*/

struct	ellipsoid
{
	double	e_a;		/* semimajor radius */
	double	e_f;		/* flattening factor (reciprical)*/
	char	*e_type;	/* year of ellipsoid */
	char	*e_comment;	/* additional comment */
};

#define	NORIES		1	/* index to use nories tables */
#define	BOWDITCH	2	/* index to use Bowditch tables */
#define	ANS		3	/* index for Australian National Speroid */

struct	ellipsoid ellipsoids[] =
{
	{ 6378137,	298.257223563, "WGS 1984",                 "",        },
	{ 6378249.145,	293.465,       "Clarke ellipsoid of 1880", "Nories",  },
	{ 6378153,	298.26,        "WGS 1972",                 "Bowditch",},
	{ 6378160,	298.25,	       "ANS 1966",		   "",	      },
};

/*
**	global variables
*/

struct	pos	vertex, from, to, last, wp;
struct	pos	cvt_pos();
int	ellips;		/* index to ellipsoid for use in calculations */

double	delta_m;	/* difference in meridional parts */
double	delta_M;	/* difference in meridional distance */
double	course;		/* rhumb course */
double	distance;	/* rhumb distance */
double	g_distance;	/* great circle distance */
double	g_course;	/* great circle initial course */
double	d_lat;		/* difference in latitude */
double	d_long;		/* difference in longitude */
double	f;		/* flattening factor for earth */
double	a;		/* semi-major axis diameter */
double	e;		/* eccentricity */
double	a_rad_nm;	/* conversion for radians to nautical miles */

double	angle, diff, partial;
double	v1, v2, v3, v4;

double	meridional_part(), meridional_dist(), atof();

char	string[132];
char	*cvt_pnt;

/*
**	mode flags
*/

char	g_circle;	/* output great circle information */
char	short_pos;	/* use shorthand notation for position */
char	debug;

// main(argc, argv)
// char *argv[];
// {
	register char *s;
	long local_time;
/*
**	decode command line parameters
*/
/*
	while(--argc)
	{
		s = *++argv;
		if(*s != '-')
			ferr("Expected '-' in command line");
		while(*++s)
			switch(*s)
			{
				case 'b':	/* use Bowditch, (WGS 1972) */
					ellips = BOWDITCH;
// 					break;

// 				case 'd':	/* output debug info */
// 					debug++;
// 					break;

// 				case 'g':	/* output great circle info */
// 					g_circle++;
// 					break;
// 
// 				case 'n':	/* use Nories (Clarke 1880) */
// 					ellips = NORIES;
// 					break;

// 				case 's':	/* use short position notation */
// 					short_pos++;
// 					break;

// 				default:
// 					ferr("Illegal option '%c'", *s);
// 			}
// 	}
// */
/*
**	output heading
*/
	local_time = time((long *)0);
	printf("Sailings Version 1.2 @ %s\n", ctime(&local_time));
/*
**	calculate ellipsoid parameters and some other constants
*/
	f = 1.0 / ellipsoids[ellips].e_f;
	e = sqrt(2.0 * f - f * f);
	a = ellipsoids[ellips].e_a;
	a_rad_nm = a * M_PI / 180.0 / 1852;
	if(debug)
	{
		printf("Using %s", ellipsoids[ellips].e_type);
		if(*ellipsoids[ellips].e_comment)
			printf(" (%s)", ellipsoids[ellips].e_comment);
		printf("\n");
		printf("a = %f, e = %f, f = 1/%f\n", a, e, 1.0 / f);
		printf("a_rad_nm = %f\n", a_rad_nm);
	}
/*
**	main loop to accept data
*/
	while(prompt("\nStart position           :- "))
	{
		from = cvt_pos(string);
	/*
	**	if no end position, assume problem type 2
	*/
		if(prompt("End position             :- ") == NULL)
			prob2();
		else
		{
			prob1();
			if(g_circle)
			{
				putchar('\n');
				while(prompt("WP Longitude             :- "))
					way_point();
				exit(0);
			}
		}
	/*
	**	remember last position
	*/
		last = to;
	}
}

/*
**	given start and finish, calculate course and distance
*/

prob1()
{
/*
**	decode final position
*/
	to = cvt_pos(string);
/*
**	calculate difference in latitude and longitude. Beware wrap round
**	in longitude
*/
	if(sign(to.p_long) == sign(from.p_long))
		d_long = to.p_long - from.p_long;
	else
	{
		if(debug)
			printf("Longitude wrap\n");
		d_long = 360.0 - fabs(to.p_long) - fabs(from.p_long);
		if(to.p_long - from.p_long >= 0.0)
			d_long = -d_long;
	}
	d_lat  = to.p_lat - from.p_lat;
/*
**	test special case of same meridian
*/
	if(to.p_lat == from.p_lat)
	{
		if(debug)
			printf("Same meridian\n");
		course = d_long > 0.0? 90.0: 270.0;
		partial = e * Sin(to.p_lat);
		distance = a_rad_nm * d_long * Cos(to.p_lat)
			   / sqrt(1 - partial * partial);
	}
/*
**	special case of parallel sailings
*/
	else if(to.p_long == from.p_long)
	{
		if(debug)
			printf("Parallel sailings\n");
		delta_m = meridional_dist(to.p_lat) - meridional_dist(from.p_lat);
		distance = fabs(delta_m * 60.0);
		course = d_lat > 0.0 ? 0.0: 180.0;
	}	
/*
**	general case
*/
	else
	{
		delta_M = meridional_part(to.p_lat) - meridional_part(from.p_lat);
		delta_m = meridional_dist(to.p_lat) - meridional_dist(from.p_lat);
		course = Atan2(d_long, delta_M);
		if(course < 0.0)
			course += 360.0;
		distance = delta_m / Cos(course);
	}
/*
**	calculate great circle distance and initial course
*/
	diff = to.p_long - from.p_long;
	partial = Sin(to.p_lat) * Sin(from.p_lat)
		  + Cos(to.p_lat) * Cos(from.p_lat) * Cos(diff);
	g_distance = 60.0 * Acos(partial);
	
	partial = Cos(from.p_lat) * Tan(to.p_lat)
		  - Sin(from.p_lat) * Cos(diff);
	angle = fabs(Atan(Sin(diff) / partial));
/*
**	Determine direction
*/
	if(course > 180)
		g_course = 180.0 + angle;
	else
		g_course = 180.0 - angle;
/*
**	calculate vertex of great circle
*/
	v1 = Tan(from.p_lat);
	v2 = Tan(to.p_lat);
	v4 = v1 * v2;
	v1 += v2;
	v2 = Cos(diff / 2.0);
	v3 = Sin(diff);
	partial = sqrt((v1 * v1 - 4.0 * v4 * v2 * v2) / (v3 * v3));
	vertex.p_lat = Atan(partial);
/*
**	determine appropriate hemisphere for latitude
*/
	if(fabs(from.p_lat) > fabs(to.p_lat))
		vertex.p_lat *= sign(from.p_lat);
	else
		vertex.p_lat *= sign(to.p_lat);
/*
**	cal longitude of vertex
*/
	partial = Atan(1.0 / (Tan(angle) * Sin(from.p_lat)));
	delta_m = fabs(partial);
	if(diff < 0)	/* heading east */
		vertex.p_long = from.p_long + delta_m;
	else		/* heading west */
		vertex.p_long = from.p_long - delta_m;
	if(debug)
		printf("diff %f, partial long %f\n", diff, vertex.p_long);
	if(vertex.p_long > 180.0)
		vertex.p_long -= 360.0;
	if(vertex.p_long < -180.0)
		vertex.p_long += 360.0;
/*
**	output result
*/
	printf("Rhumb Course             :- %6.1f\n", course);
	printf("Rhumb Distance           :- %6.1f\n", fabs(distance));
	if(g_circle)
	{
		printf("Great Circle Course      :- %6.1f\n", g_course);
		printf("Great Circle Distance    :- %6.1f\n", fabs(g_distance));
		printf("Great Circle Vertex      :- ");
		out_pos(vertex);
	}
/*
**	debug code
*/
	if(debug)
	{
		printf("D.lat %f, D.long %f\n", d_lat, d_long);
		printf("delta_m %f, delta_M %f\n", delta_m, delta_M);

		printf("Initial position (%f, %f) ", from.p_lat, from.p_long);
		out_pos(from);
		printf("Final position   (%f, %f) ", to.p_lat, to.p_long);
		out_pos(to);
		printf("diff %f, angle %f\n", diff, angle);
	}
}

/*
**	calculate way point for given longitude
*/

way_point()
{
	register char *s;
	register double part;

	s = cvt_pnt = string;
/*
**	get whole degrees longitude
*/
	SKIP_SPACES();
	if(!isdigit(*s))
		cvt_err(s, "Expected digit, got '%c'", *s);
	wp.p_long = atof(s);
	if(wp.p_long < 0.0 || wp.p_long > 180.0)
		cvt_err(s, "Longitude out of range");
/*
**	look for possible east/west or minutes
*/
	SKIP_DIGITS();
	SKIP_SPACES();
	if(isdigit(*s))
	{
		part = atof(s);
		if(part < 0.0 || part > 60.0)
			cvt_err(s, "Longitude out of range");
		wp.p_long += part / 60.0;
		SKIP_FLOATS();
		SKIP_SPACES();
	}
	switch(*s)
	{
		case 'E':
		case 'e':
			s++;
// 		case NULL:
// 			break;

		case 'W':
		case 'w':
			s++;
			wp.p_long = -wp.p_long;
			break;

		default:
			cvt_err(s, "Unexpected character in Longitude '%c'", *s);
	}
/*
**	check for proper termination
*/
	SKIP_SPACES();
	if(*s != NULL)
		cvt_err(s, "Extra characters at end of line");
/*
**	calculate latitude from way point longitude
*/
	if(sign(wp.p_long) == sign(from.p_long))
		d_long = wp.p_long - from.p_long;
	else
		d_long = 360.0 - fabs(wp.p_long) - fabs(from.p_long);
	v1 = fabs(d_long);
	v2 = fabs(from.p_lat);
	wp.p_lat = Atan2(Sin(v2) * Cos(v1) + Sin(v1) * 1.0 / Tan(angle),
		    Cos(v2));
	wp.p_lat *= sign(vertex.p_lat);
	printf("Great Circle WP          :- ");
	out_pos(wp);
	putchar('\n');
}

/*
**	second problem type. given course and distance, cal new position
*/

prob2()
{
	while(prompt("Course                   :- "))
	{
		to = from;
		course = atof(string);
		if(course < 0.0 || course > 360.0)
			ferr("Illegal course");
		prompt("Distance                 :- ");
		distance = atof(string);
		if(distance <= 0.0)
			ferr("Illegal distance");
	/*
	**	special case for course of 0 or 180 degrees
	*/
		if(course == 0.0 || course == 180.0)
		{
			recurs();
			if(debug)
				printf("Same parallel\n");
		}
	/*
	**	special case for course of 90 or 270
	*/
		else if(course == 90.0 || course == 270.0)
		{
			partial = e * Sin(from.p_lat);
			d_long = distance * sqrt(1 - partial * partial) /
				(a_rad_nm * Cos(from.p_lat));
			to.p_long += (course == 90.0)? d_long: -d_long;
			if(debug)
				printf("Same meridian\n");
		}
	/*
	**	general case
	*/
		else
		{
			recurs();
			delta_M = meridional_part(to.p_lat) - meridional_part(from.p_lat);
			d_long = fabs(delta_M * Tan(course));
			to.p_long += (course < 180.0)? d_long: -d_long;
		}
	/*
	**	cope with crossing the date line
	*/
		if(to.p_long > 180.0)
			to.p_long -= 360.0;
		else if(to.p_long < -180.0)
			to.p_long += 360.0;
	/*
	**	output new position
	*/
		printf("New position             :- ");
		out_pos(to);
	/*
	**	remember new position
	*/
		from = to;
	}
}

/*
**	calculate the meridional distance for the requested latitude
*/

double meridional_dist(lat)
double lat;
{
	double md, e2, e4, e6;

	e2 = e * e;
	e4 = e2 * e2;
	e6 = e4 * e2;
	v1 = M_PI/180.0 * (1.0 - e2 / 4.0 - 3.0 * e4 / 64.0 - 5.0 * e6 / 256.0);
	v2 = 3.0 /8.0 * (e2 - e4 / 4.0 + 15.0 * e6 / 128.0);
	v3 = 15.0 / 256.0 * (e4 + 3.0 * e6 / 4.0);
	v4 = a / 1852.0;
	md = v4 * (v1 * lat - v2 * Sin(2.0 * lat) + v3 * Sin(4.0 * lat));
	if(debug)
		printf("meridional factors A0 %g, A2 %g, A4 %g\n",
			v1 * v4, v2 * v4, v3 * v4);
	return(md);
}

/*
**	calculate the meridional part for the requested latitude
*/

double meridional_part(lat)
double lat;
{
	double mp, part;

	part = e * Sin(lat);
	mp = TODEG(log(Tan(45.0 + lat / 2.0))
	     - 0.5 * e * log((1 + part) / (1 - part)));
	return(mp);
}

/*
**	calculate new latitude from course and distance
*/

recurs()
{
	register int iteration;
	double m_from, m_guess, m_partial, lat;

	m_from = meridional_dist(from.p_lat);
	m_guess = m_from + distance * Cos(course);
	lat = from.p_lat + (m_guess - m_from) / 60.0;
	for(iteration = 0; iteration < 10; iteration++)
	{
		m_partial = meridional_dist(lat);
		lat = lat + (m_guess - m_partial) / 60.0;
	}
	to.p_lat = lat;
}

/*
**	return sign of argument
*/

sign(val)
double val;
{
	return(val >= 0.0? 1: -1);
}

/*
**	convert the input string to a lat and long position
**
**	input is free form but must be N/S followed by E/W.
**	minutes are optional and the case doesn't matter.
**	white space is ignored.
**	N and E are +ve
**	S and W are -ve
*/

struct pos cvt_pos(s)
register char *s;
{
	static struct pos result;
	double part;

	cvt_pnt = s;
/*
**	special case. the keyword 'last' return the last position obtained
*/
	if(strcmp(s, "last") == NULL)
	{
		printf("Last position            :- ");
		out_pos(last);
		return(last);
	}
/*
**	get whole degrees latitude
*/
	SKIP_SPACES();
	if(!isdigit(*s))
		cvt_err(s, "Expected number, got '%c'", *s);
	result.p_lat = atof(s);
	if(result.p_lat < 0.0 || result.p_lat > 90.0)
		cvt_err(s, "Latitude out of range");
/*
**	look for possible hemisphere or minutes. If there is a period after
**	digits, then assume fractional degrees. In this case, the previous
**	atof saw it, so skip remining digits
*/
	SKIP_DIGITS();
	if(*s == '.')
	
		s++;
		SKIP_DIGITS();
	
	SKIP_SPACES();
/*
**	any digits left must be minutes
*/
	if(isdigit(*s))
	{
		part = atof(s);
		if(part < 0.0 || part > 60.0)
			cvt_err(s, "Latitude out of range");
		result.p_lat += part / 60.0;
		SKIP_FLOATS();
		SKIP_SPACES();
	}
	switch(*s)
	{
		case 'N':
		case 'n':
			s++;
		case ',':
			break;

		case 'S':
		case 's':
			s++;
			result.p_lat = -result.p_lat;
			break;

// 		case NULL:
			cvt_err(s, "Unexpected end of line");
		default:
			cvt_err(s, "Unexpected character in Latitude '%c'", *s);

	}
/*
**	decode longitude, skip optional comma
*/
	SKIP_SPACES();
	if(*s == ',')
	{
		s++;
		SKIP_SPACES();
	}
/*
**	get whole degrees longitude
*/
	SKIP_SPACES();
	if(!isdigit(*s))
		cvt_err(s, "Expected digit, got '%c'", *s);
	result.p_long = atof(s);
	if(result.p_long < 0.0 || result.p_long > 180.0)
		cvt_err(s, "Longitude out of range");
/*
**	look for possible east/west or minutes. If there is a period after
**	digits, then assume fractional degrees. In this case, the previous
**	atof saw it, so skip remining digits
*/
	SKIP_DIGITS();
	if(*s == '.')
	{
		s++;
		SKIP_DIGITS();
	}
	SKIP_SPACES();
	if(isdigit(*s))
	{
		part = atof(s);
		if(part < 0.0 || part > 60.0)
			cvt_err(s, "Longitude out of range");
		result.p_long += part / 60.0;
		SKIP_FLOATS();
		SKIP_SPACES();
	}
	switch(*s)
	{
		case 'E':
		case 'e':
			s++;
// 		case NULL:
// 			break;

		case 'W':
		case 'w':
			s++;
			result.p_long = -result.p_long;
			break;

		default:
			cvt_err(s, "Unexpected character in Longitude '%c'", *s);
	}
/*
**	check for proper termination
*/
	SKIP_SPACES();
	if(*s != NULL)
		cvt_err(s, "Extra characters at end of line");
/*
**	return value
*/
	return(result);
}

/*
**	handle conversion error
*/

/* VARARGS */

cvt_err(pos, format, arg)
char *pos, *format;
int arg;
{
	register int cnt;

	printf("\nConversion error :- ");
	printf(format, arg);
	printf("\n%s\n", cvt_pnt);
	cnt = pos - cvt_pnt;
	while(cnt--)
		putchar(' ');
	printf("^\n\n");
	exit(1);
/* NOTREACHED */
}

/*
**	output position in Lat/Long format
*/

out_pos(p)
struct pos p;
{
	register char c;

	c = (p.p_lat >= 0.0)? 'N': 'S';
	out_deg("Lat", p.p_lat, c);
	printf(", ");
/*
**	correct wrap round
*/
	if(p.p_long > 180.0)
		p.p_long = 360.0 - p.p_long;
	else if(p.p_long < -180.0)
		p.p_long += 360.0;
	c = p.p_long >= 0.0? 'E': 'W';
	out_deg("Long", p.p_long, c);
	printf("\n");
}

/*
**	output position in degreesand minutes
**	allow for rounding errors like 1 deg 60 min!
*/

out_deg(s, deg, c)
char *s, c;
double deg;
{
	register int whole_degrees;
	double dg, minutes;

	dg = fabs(deg);
	whole_degrees = dg;
	minutes = (dg - floor(dg)) * 60.;
	while(minutes >= 60.0 - .001)
	{
		whole_degrees++;
		minutes -= 60.0;
	}
	if(minutes != 0.0)
		minutes += 0.05;
	if(short_pos)
		printf("%d %3.1f", whole_degrees, minutes);
	else
		printf("%s %3d deg %3.1f min ", s, whole_degrees, minutes);
	if(c)
		printf("%c", c);
}

/*
**	prompt for an input string, return length
*/

prompt(s)
char *s;
{
	register int length;

/*
**	if running from redirected input, allow possibility of
**	comments begining with # and echo any input
*/
	if(isatty(0) == NULL)
	{
		for(EVER)
		{
			if(fgets(string, sizeof string, stdin) == NULL)
				exit(0);
		/*
		**	test for comment
		*/
			if(*string == '#')
			{
				printf("\n%s", string);
				continue;
			}
		/*
		**	otherwise, output prompt then input line
		*/
			else
				printf("%s%s", s, string);
			break;
		}
	}
/*
**	interactive input. output prompt then collect input line.
*/
	else
	{
		printf(s);
		if(fgets(string, sizeof string, stdin) == NULL)
			exit(0);
	}
/*
**	remove trailing line feed
*/
	length = strlen(string) - 1;
	string[length] = 0;
	return(length);
}

/*
**	handle fatal errors
*/
/* VARARGS */

ferr(format, args)
char *format;
double args;
{
	printf("\n");
	printf(format, args);
	printf("\n");
	exit(1);
/* NOTREACHED */
}


