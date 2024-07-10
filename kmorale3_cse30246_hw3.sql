/* Katie Morales Databases HW 3 */

/* Question 1 total spectators */

select sum(attendance) as total_attendance from cfb_game_stats ;

/* Question 2 How many times did a PUNT occur on a non-fourth down play */

select count(*) as total_punts from cfb_play where play_type = 'PUNT' and down != 4 ;

/* Question 3 The Red zone is when the ball is within the 20 yards of the goal line. A red zone attempt is when the team moves inside the red zone, and a successful red zone attempt is when a touchdown is scored. Which 5 schools with over 20 red zone attempts have the best red zone success rate (%) and what was their success rate?
        this query gets the total red zone attempts
            select team_id, sum(red_zone_attempt) as red_zone_attempt from cfb_drive group by team_id; 
        this query gets the total successful red zone attempts
            select team_id, sum(red_zone_attempt) as successful_red_zone_attempt from cfb_drive where end_reason = 'TOUCHDOWN' group by team_id limit 5;
        this query combines everything to get the name of the school and the rate 
            select distinct name, rate from (select A.team_id, successful_red_zone_attempt/red_zone_attempt as rate from (select team_id, sum(red_zone_attempt) as red_zone_attempt from cfb_drive group by team_id) A, (select team_id, sum(red_zone_attempt) as successful_red_zone_attempt from cfb_drive where end_reason = 'TOUCHDOWN' group by team_id) B where A.team_id = B.team_id and red_zone_attempt >= 20) C, cfb_team where C.team_id = cfb_team.team_id order by rate desc limit 5;
*/

select distinct name, rate from (select A.team_id, successful_red_zone_attempt/red_zone_attempt as rate from (select team_id, sum(red_zone_attempt) as red_zone_attempt from cfb_drive group by team_id) A, (select team_id, sum(red_zone_attempt) as successful_red_zone_attempt from cfb_drive where end_reason = 'TOUCHDOWN' group by team_id) B where A.team_id = B.team_id and red_zone_attempt >= 20) C, cfb_team where C.team_id = cfb_team.team_id order by rate desc limit 5 ;

/* Question 4 Which school has the most pass plays; which school has the highest percentage of pass plays; and are these the same team 
        this query gets the total number of pass attempts
            select team_id, sum(attempt) as num_passes from cfb_pass group by team_id;
        this query returns the team nsme and number of passes for the team with the most passes
            select name as most_pass_team, num_passes from (select team_id, sum(attempt) as num_passes from cfb_pass group by team_id) A, cfb_team where A.team_id = cfb_team.team_id order by num_passes desc limit 1;
        this query returns the team name and pct_passes for the team with the highest pct passes
            select name as highest_pct_pass_team, (pass_attempts/plays) as pct_passes from (select team_id, sum(attempt) as pass_attempts from cfb_pass group by team_id) B, (select offense_team_id, count(play_type) as plays from cfb_play group by offense_team_id) C, cfb_team where B.team_id = offense_team_id and B.team_id = cfb_team.team_id order by pct_passes desc limit 1;

            select most_pass_team, num_passes, highest_pct_pass_team, pct_passes, (most_pass_team = highest_pct_pass_team) as 'same_team?' from (select name as most_pass_team, num_passes from (select team_id, sum(attempt) as num_passes from cfb_pass group by team_id) A, cfb_team where A.team_id = cfb_team.team_id order by num_passes desc limit 1) TEAM_MOST_PASSES, (select name as highest_pct_pass_team, (pass_attempts/plays) as pct_passes from (select team_id, sum(attempt) as pass_attempts from cfb_pass group by team_id) B, (select offense_team_id, count(play_type) as plays from cfb_play group by offense_team_id) C, cfb_team where B.team_id = offense_team_id and B.team_id = cfb_team.team_id order by pct_passes desc limit 1) TEAM_PCT_PASSES;
*/

select most_pass_team, num_passes, highest_pct_pass_team, pct_passes, (most_pass_team = highest_pct_pass_team) as 'same_team?' from (select name as most_pass_team, num_passes from (select team_id, sum(attempt) as num_passes from cfb_pass group by team_id) A, cfb_team where A.team_id = cfb_team.team_id order by num_passes desc limit 1) TEAM_MOST_PASSES, (select name as highest_pct_pass_team, (pass_attempts/plays) as pct_passes from (select team_id, sum(attempt) as pass_attempts from cfb_pass group by team_id) B, (select offense_team_id, count(play_type) as plays from cfb_play group by offense_team_id) C, cfb_team where B.team_id = offense_team_id and B.team_id = cfb_team.team_id order by pct_passes desc limit 1) TEAM_PCT_PASSES ;

/* Question 5 Which Notre Dame player had the most yards on 1st down 

get the yards for passers, rushers, and receivers
    select player_id, sum(yards) as rush_yards from cfb_rush where player_id in (select player_id from cfb_player, cfb_team where name = 'Notre Dame' and cfb_player.team_id = cfb_team.team_id) group by player_id;
    select passer_player_id, sum(yards) as passer_yards from cfb_pass where passer_player_id in (select player_id from cfb_player, cfb_team where name = 'Notre Dame' and cfb_player.team_id = cfb_team.team_id) group by passer_player_id
    select receiver_player_id, sum(yards) as receiver_yards from cfb_pass where receiver_player_id in (select player_id from cfb_player, cfb_team where name = 'Notre Dame' and cfb_player.team_id = cfb_team.team_id) group by receiver_player_id
combine results
    select distinct player from ((select player_id as player, sum(yards) as yards from cfb_rush where player_id in (select player_id from cfb_player, cfb_team where name = 'Notre Dame' and cfb_player.team_id = cfb_team.team_id) group by player_id) union (select passer_player_id as player, sum(yards) as yards from cfb_pass where passer_player_id in (select player_id from cfb_player, cfb_team where name = 'Notre Dame' and cfb_player.team_id = cfb_team.team_id) group by passer_player_id) union (select receiver_player_id as player, sum(yards) as yards from cfb_pass where receiver_player_id in (select player_id from cfb_player, cfb_team where name = 'Notre Dame' and cfb_player.team_id = cfb_team.team_id) group by receiver_player_id)) players, cfb_player where cfb_player.player_id = player group by player order by sum(yards) desc;
*/

select first_name, last_name from (select player as final_player, sum(yards) as total_yards from ((select player_id as player, sum(yards) as yards from cfb_rush where player_id in (select player_id from cfb_player, cfb_team where name = 'Notre Dame' and cfb_player.team_id = cfb_team.team_id) group by player_id) union (select passer_player_id as player, sum(yards) as yards from cfb_pass where passer_player_id in (select player_id from cfb_player, cfb_team where name = 'Notre Dame' and cfb_player.team_id = cfb_team.team_id) group by passer_player_id) union (select receiver_player_id as player, sum(yards) as yards from cfb_pass where receiver_player_id in (select player_id from cfb_player, cfb_team where name = 'Notre Dame' and cfb_player.team_id = cfb_team.team_id) group by receiver_player_id)) players, cfb_player where cfb_player.player_id = player group by player order by sum(yards) desc) players_yards, cfb_player where cfb_player.player_id = final_player order by total_yards desc limit 1 ;

/* Question 6 From which state does Notre Dame receive most of its players? How many does that state send, and what percentage of ND players come from that state?

get the sum of homestate counts 
    select homestate, count(*) as cnt from (select distinct cfb_player.player_id, cfb_player.team_id, cfb_player.homestate from cfb_player, cfb_team where name = 'Notre Dame' and cfb_player.team_id = cfb_team.team_id) notre_dame_players group by homestate having homestate is not null order by cnt;

get the total number of nd players that have a homestate listed 
    select count(*) from (select distinct player_id as total_ND_players from cfb_player, cfb_team where name = 'Notre Dame' and cfb_player.team_id = cfb_team.team_id and homestate is not null) total_players;
*/

select homestate, cnt, cnt/total_ND_players as perc from (select homestate, count(*) as cnt from (select distinct cfb_player.player_id, cfb_player.team_id, cfb_player.homestate from cfb_player, cfb_team where name = 'Notre Dame' and cfb_player.team_id = cfb_team.team_id) notre_dame_players group by homestate having homestate is not null) players_by_state, (select count(*) as total_ND_players from (select distinct player_id as total_ND_players from cfb_player, cfb_team where name = 'Notre Dame' and cfb_player.team_id = cfb_team.team_id and homestate is not null) total_players) players order by cnt desc limit 1 ;

/* 8. Which stadium has sees the longest punt returns on average, and how long is that average? 

join all the necessary tables to get the punt return yards, stadium_id and stadium name 
    select distinct cfb_punt_return.game_id, cfb_punt_return.play_number, cfb_punt_return.yards, cfb_game.stadium_id, cfb_stadium.name from cfb_punt_return, cfb_game, cfb_stadium where cfb_punt_return.game_id = cfb_game.game_id and cfb_game.stadium_id = cfb_stadium.stadium_id
*/

select name, sum(yards)/count(*) as yards from (select distinct cfb_punt_return.game_id, cfb_punt_return.play_number, cfb_punt_return.yards, cfb_game.stadium_id, cfb_stadium.name from cfb_punt_return, cfb_game, cfb_stadium where cfb_punt_return.game_id = cfb_game.game_id and cfb_game.stadium_id = cfb_stadium.stadium_id) stadium_yards group by name order by yards desc limit 1 ;

/* 9. Which stadium has witnessed the home team lose the most times? 

get defense losses
    select A.stadium_id, defense_losses from (select stadium_id, sum(loss) as defense_losses from (select stadium_id, offsense_points > defense_points as loss from (select game_id, max(play_number) as final from cfb_play group by game_id) final_play_def, cfb_game, cfb_play where final_play_def.game_id = cfb_game.game_id and cfb_play.game_id = final_play_def.game_id and cfb_play.play_number = final_play_def.final and defense_team_id = home_team_id) def_stadium group by stadium_id) A, cfb_stadium where A.stadium_id = cfb_stadium.stadium_id order by defense_losses

get offense losses
    select B.stadium_id, offense_losses as losses from (select stadium_id, sum(loss) as offense_losses from (select stadium_id, offsense_points < defense_points as loss from (select game_id, max(play_number) as final from cfb_play group by game_id) final_play_off, cfb_game, cfb_play where final_play_off.game_id = cfb_game.game_id and cfb_play.game_id = final_play_off.game_id and cfb_play.play_number = final_play_off.final and offense_team_id = home_team_id) off_stadium group by stadium_id) B, cfb_stadium where B.stadium_id = cfb_stadium.stadium_id order by offense_losses;

*/

select name, total_losses as home_losses from (select stadium_id, sum(losses) as total_losses from ((select A.stadium_id, defense_losses as losses from (select stadium_id, sum(loss) as defense_losses from (select stadium_id, offsense_points > defense_points as loss from (select game_id, max(play_number) as final from cfb_play group by game_id) final_play_def, cfb_game, cfb_play where final_play_def.game_id = cfb_game.game_id and cfb_play.game_id = final_play_def.game_id and cfb_play.play_number = final_play_def.final and defense_team_id = home_team_id) def_stadium group by stadium_id) A, cfb_stadium where A.stadium_id = cfb_stadium.stadium_id order by defense_losses) union (select B.stadium_id, offense_losses as losses from (select stadium_id, sum(loss) as offense_losses from (select stadium_id, offsense_points < defense_points as loss from (select game_id, max(play_number) as final from cfb_play group by game_id) final_play_off, cfb_game, cfb_play where final_play_off.game_id = cfb_game.game_id and cfb_play.game_id = final_play_off.game_id and cfb_play.play_number = final_play_off.final and offense_team_id = home_team_id) off_stadium group by stadium_id) B, cfb_stadium where B.stadium_id = cfb_stadium.stadium_id order by offense_losses)) home_team_losses group by stadium_id order by total_losses desc limit 1) most_home_losses, cfb_stadium where most_home_losses.stadium_id = cfb_stadium.stadium_id ;


/* 10. Which player(s) had the longest reception in the 4th quarter. What team where they on and what year was it? (breaking non-trivial ties is 5 of the 15 points, (i.e 10 points with LIMIT, 20 points without LIMIT) 

get 4th quarter pass plays 
    select play_number, game_id from cfb_play where period = 4 and play_type='PASS';

get receiver id along with yards 
    select receiver_player_id, yards from cfb_play, cfb_pass where cfb_play.game_id = cfb_pass.game_id and cfb_play.play_number = cfb_pass.play_number and period = 4 and play_type='PASS'
*/

select distinct first_name, last_name, name, player_info.year from (select first_name, last_name, team_id, year from (select receiver_player_id, yards, year(game_date) as year from (select receiver_player_id, yards, game_date from cfb_play, cfb_pass, cfb_game where cfb_game.game_id = cfb_play.game_id and cfb_play.game_id = cfb_pass.game_id and cfb_play.play_number = cfb_pass.play_number and period = 4 and play_type='PASS') quarter4_rec_yards, (select max(yards) as longest_rec from (select receiver_player_id, yards from cfb_play, cfb_pass where cfb_play.game_id = cfb_pass.game_id and cfb_play.play_number = cfb_pass.play_number and period = 4 and play_type='PASS') quarter4_rec_yards) longest where yards = longest_rec) players_longest_rec, cfb_player where receiver_player_id = player_id) player_info, cfb_team where player_info.team_id = cfb_team.team_id ;

/* 11. Of all the schools that are not in a conference, i.e., “Ind”, Notre Dame is certainly the heaviest. But how much heavier, exactly? Compare the average weight of all the players on Notre Dame against the average weight of players on other teams that are also not part of a conference.

get the average weight for notre dame
    select team_id, sum(weight)/count(*) as ND_avg_weight from (select distinct cfb_player.player_id, cfb_player.team_id, cfb_player.weight from cfb_player, cfb_team where cfb_player.team_id = cfb_team.team_id and name = "Notre Dame" and weight is not null) ND group by team_id

get the avg weight for the other independent teams (sum together the total num of players and weights... then take the average)
    select sum(ind_weights)/sum(ind_counts) as ind_avg_weights from (select cfb_player.team_id as ind_schools, sum(weight) as ind_weights, count(*) as ind_counts from (select distinct cfb_player.player_id, cfb_player.team_id from cfb_player, cfb_team, cfb_conference where cfb_player.team_id = cfb_team.team_id and cfb_team.conference_id = cfb_conference.conference_id and (cfb_conference.name = "Independent" or cfb_conference.name = "Ind") and cfb_team.name != "Notre Dame"and weight is not null) ind_teams, cfb_player where cfb_player.team_id = ind_teams.team_id and cfb_player.player_id = ind_teams.player_id group by cfb_player.team_id) ind_avg_weights

*/

select (ND_avg_weight - ind_avg_weights) as wgt_diff from (select team_id, sum(weight)/count(*) as ND_avg_weight from (select distinct cfb_player.player_id, cfb_player.team_id, cfb_player.weight from cfb_player, cfb_team where cfb_player.team_id = cfb_team.team_id and name = "Notre Dame" and weight is not null) ND group by team_id) ND_WEIGHT, (select sum(ind_weights)/sum(ind_counts) as ind_avg_weights from (select cfb_player.team_id as ind_schools, sum(weight) as ind_weights, count(*) as ind_counts from (select distinct cfb_player.player_id, cfb_player.team_id from cfb_player, cfb_team, cfb_conference where cfb_player.team_id = cfb_team.team_id and cfb_team.conference_id = cfb_conference.conference_id and (cfb_conference.name = "Independent" or cfb_conference.name = "Ind") and cfb_team.name != "Notre Dame"and weight is not null) ind_teams, cfb_player where cfb_player.team_id = ind_teams.team_id and cfb_player.player_id = ind_teams.player_id group by cfb_player.team_id) ind_avg_weights) IND_WEIGHT ;
