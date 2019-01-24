limi,m=map(int,input().split())
#limi=101
limi+=1
fac=[0]*limi
fac[0]=1
for i in range(1,limi):
  fac[i]=fac[i-1]*i
#m=1000000
res=0
for i in range(1,limi):
  for j in range(i+1):
    n=fac[i]//(fac[i-j]*fac[j])
    if n > m:
      #print(n)
      res+=1
print(res)


"""
function mapFun(x,y){
  let numero=x.itemGroup+x.position;
  let nombre=x.extendedData.nombres;
  nombre=!nombre?numero:numero+" - "+nombre.primerNombre()+" "+x.extendedData.apellidos.iniciales(); 
  let list=x._links.list;
  let cat=x.extendedData.categoria||"-";
  let ultLLamado=x.log.items.reduce(getUltimaNotificacion,0);
  if(list.includes("triage")){
    list="Triage";
  }else if(list.includes("admision")){
    list="Admisión";
  }else if(list.includes("urgencia")){
    list="Box Urgencia";
  }
  return {"nombre":nombre,"numero":numero,"cat":cat,"list":list,"ult":ultLLamado,"modulo":"m","notices":x.notices};
}

//agrega la iformacion a la tabla
function actualizaUrgencia(resp){
  //resp.items.forEach((x,y,z)=>{if(!x._links.list.includes("admision")){t=z.find((q)=>q.ownerId===x.ownerId&&q._links.list.includes("admision"));if(t!==undefined){x.position=t.position;x.itemGroup=t.itemGroup;}}});
  z=resp;
	g=uniqueOwnerIdAndOwnerName(resp.items.filter(funFiltro)).map(funMap).sort(ordenarPorUlt)
  .slice(0,15);
  g.forEach(function(currV,ind,arr){
    currV.reciente=(arr[0].ult-currV.ult)<60;
    currV.anima=false;
  });

  let este=g.map(x=>JSON.stringify(x)).join();
  if(ultimo.localeCompare(este)){
    ultimo=este;
    if(g.length>0){
      esteult=g[0].ult;
      if(lastCalled<esteult){
        beep();
        g.forEach((x)=>{
          x.anima=x.reciente;
        });
        lastCalled=esteult;
      }
    }
  }
  vue.lista=g;
  
  setTimeout(desanima,1000);
}
"""