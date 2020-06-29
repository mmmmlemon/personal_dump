<template>
  <div class="row justify-content-center">
      <div class="col-md-8">
       <h2>settings page</h2>
      </div>
  </div>
</template>

<script>
export default {
   mounted(){
       this.$parent.currentPage = "settings"
   }
}
</script>