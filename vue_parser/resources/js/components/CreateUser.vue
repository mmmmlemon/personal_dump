<template>
  <div class="container justify-content-center">
    <h1>Add new Steam User</h1>
    <form @submit.prevent="addUser">
      <div class="row justify-content-center">
        <div class="col-md-6 justify-content-center">
          <div class="form-group">
            <label>User name</label>
            <input type="text" class="form-control" v-model="steamuser.username">
            <label>Steam ID</label>
            <input type="text" class="form-control" v-model="steamuser.steam_id">
          </div>
        </div>
        </div>
        <div class="form-group">
          <button class="btn btn-success">Create</button>
        </div>
    </form>
  </div>
</template>


<script>
    export default {
        data(){
        return {
          steamuser:{}
        }
    },
   
    methods: {
      addUser(){
          console.log(this.steamuser)
       let uri = './api/steamuser/create';
       this.axios.post(uri, this.steamuser).then((response) => {
           this.$router.push({name: 'userspage'});
       })
      }
    }
  }
</script>