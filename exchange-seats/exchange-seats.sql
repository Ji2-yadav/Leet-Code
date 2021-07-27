
select(case 
      when mod(id,2)!=0 && id!=total then id+1
      when mod(id,2)!=0 && id=total then id
      else id-1
      end) as Id,student from
      (select count(*) as total from seat)as record,seat
      order by id